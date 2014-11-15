	for(int p1=0; p1<v1.size();p1++)
		{
			vector<int> temp;
			temp.push_back(v1[0].a);
			temp.push_back(v1[0].b);
			vector<frnd_list>::iterator p=v1.begin();
			v1.erase(p);
			for(int i=0;i<temp.size();i++)
			{
				p=v1.begin();
				for(int j=0;j<v1.size();j++)
				 {
				 	if(v1[j].a==temp[i])
				 	{
				 		int flag=0;
						 for(int k=0;k<temp.size();k++)
				 		{
				 			if(temp[k]==v1[j].b)
				 			flag=1;
						}
						 if(flag==0)
						 temp.push_back(v1[i].b);
				 		v1.erase(p);
					 }
				  	p++;
				 }
			}
		*c=temp.size()%MOD;
	     c++;
		}
