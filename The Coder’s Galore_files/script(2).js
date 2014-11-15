/**
 * ------------------------------------------------------------------------
 * JA SideNews Module for Joomla 2.5
 * ------------------------------------------------------------------------
 * Copyright (C) 2004-2011 J.O.O.M Solutions Co., Ltd. All Rights Reserved.
 * @license - GNU/GPL, http://www.gnu.org/licenses/gpl.html
 * Author: J.O.O.M Solutions Co., Ltd
 * Websites: http://www.joomlart.com - http://www.joomlancers.com
 * ------------------------------------------------------------------------
 */
var $defined = function(obj){
			    return (obj != undefined);
			};
JaSlidingBox = new Class( {
		initialize: function( options ){
			// options setting.
			this.options = Object.append({
				mode		   : "caption", 	// it is a mode to play direction
				wrapperId	   : null,	    	// the wrapper contain elements using for sidebox 
				itemClass	   : "ja-sidenews", // this is block item.
				itemCoverClass : "ja-slidenews-cover",// class of item will use sidebox
				eventRaising   : "hover",      // run direction with a centain event.
				start		   : 20,		   // start pointer
				end            : 200,          // end pointer
				fullsize 	   : 0,            // if set fullsize is 1 without value of start, end.
				opacity	       : 80            // apply for sideitem.
			}, options || {} );

			this.Fx = null;
			// events as default 
			this.events = { onclick : ['click','click'], hover:['mouseenter',  'mouseleave'] };
			//there're modes as default
			this.modes = { 
			   caption	 : ["height"], 
			   sideright : ["left"], 
			   sideleft  : ["left"], 
			   sidedown	 : ['top'],
			   sidetop	 : ['top'],
			   botleft   : ['top'] 
			};
			
			var itemsOpacity = $$( "#"+this.options.wrapperId+" .ja-opacity" );	
			var items 		 = $$( "#"+this.options.wrapperId+" ." + this.options.itemClass );
			var itemsCover 	 = $$( "#"+this.options.wrapperId+" ." + this.options.itemCoverClass );
			
			if( $defined(itemsOpacity) ){  
				itemsOpacity.setStyles( {'opacity': this.options.opacity/100, 'filter':'alpha(opacity='+this.options.opacity+')' } );
			}
			
			if( $defined(itemsCover) ){
				items.setStyle("display","block");
				// using for auto fulsize mode
				if( this.options.fullsize == 1 ){
					this.options.start = 0;
					if( this.modes[this.options.mode][0] == 'left' ){
						if(items[0]){
							this.options.end = items[0].offsetWidth;
						}
					} else {
						if(items[0]){
							this.options.end = items[0].offsetHeight;
						}
					}
				}
					
				this.Fx = new Fx.Elements( itemsCover, Object.append({ wait: false, duration: 250 }, this.options.fxOptions || {} ) );
				var params = { 'items':items, 'itemsCover': itemsCover };
				return this.__callMethod( "sildingContent", params );
			}	
		},
		
		__callMethod:function( methodName, param ){
			// if method animation existed
			try { 
				if( $defined(this[methodName]) ){
					return this[methodName](param);	
				}
				return true;
			}catch( ex ){
				throw( "JASlidingBox : has runtime error, it is in the ''"+methodName+"'() method', please check again." );
			} 	
			return false;
		},
		
		getFxObjectByMode: function( mode, start, end ){
	
			switch( mode ){
				case 'sideright' : return { 'left': [start, -end] } ; break;
				case 'sideleft'  : return { 'left': [start, end]  } ; break;	
				case 'sidetop'   : return { 'top':  [start, end]   } ; break;
				case 'sidedown'  : return { 'top':  [start, -end]  } ;  break;	
				case 'botleft' : return	  { 'top': start , 'left': end  } ;  break;	
				default: return { 'height': [start, end] };		break;		
			}
		},
		
		sildingContent:function( params ){
			params['items'].each( function(item, index ) {
				
				item.addEvent( this.events[this.options.eventRaising][0], function(){
					var obj = {}; 
					obj[index] = this.getFxObjectByMode( this.options.mode, this.options.start, this.options.end );		
								
					params['itemsCover'].each( function(other, jindex ) { 
						if( index != jindex ) { 
							var end = other.getStyle(this.modes[this.options.mode][0]).toInt();
							if( end != this.options.start ) {
								obj[jindex] = this.getFxObjectByMode( this.options.mode, end, this.options.start );
							}
						}
					}.bind(this) );
					// start run animation	
					this.Fx.cancel();
					this.Fx.start( obj );
					 
				}.bind(this) );
				item.addEvent( this.events[this.options.eventRaising][1], function(){
					var obj = {};  
					params['itemsCover'].each( function(other, jindex ) { 
						var end = other.getStyle(this.modes[this.options.mode][0]).toInt();
						obj[jindex] = this.getFxObjectByMode( this.options.mode, end, this.options.start );
					}.bind(this) );	
					// start run animation	
					this.Fx.cancel();
					this.Fx.start( obj );
				}.bind(this) );
				
				// set default
				params['itemsCover'][index].setStyle( this.modes[this.options.mode][0], this.options.start );
			}.bind(this) );
		}
	} );