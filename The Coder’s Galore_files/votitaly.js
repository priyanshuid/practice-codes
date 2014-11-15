/*
# "VOTItaly" Plugin for Joomla! 1.5.x - Version 1.2
# License: http://www.gnu.org/copyleft/gpl.html
# Authors: Luca Scarpa & Silvio Zennaro
# Copyright (c) 2006 - 2009 Siloos snc - http://www.siloos.it
# Project page at http://www.joomitaly.com - Demos at http://demo.joomitaly.com
# ***Last update: Aug 27th, 2009***
# Modified by Kirungi Fred Fideri for VideoFlow - www.videoflow.tv
# Last modification: July 2011
*/

var VotitalyPlugin = new Class ({
	options: {
    submiturl: '/index.php?option=com_videoflow&task=vote&format=raw',
		loadingimg: '/components/com_videoflow/extra/votitaly/images/loading.gif',
		show_stars: true,
		star_description: 'undefined',
		language: {
			updating: 'undefined',
			thanks: 'undefined',
			already_vote: 'undefined',
			votes: 'undefined',
			vote: 'undefined',
			average: 'undefined',
			outof: 'undefined',
			error1: 'undefined',
			error2: 'undefined',
			error3: 'undefined',
			error4: 'undefined',
			error5: 'undefined'
			}
  },
  initialize: function(options){
    this.setOptions(options);
		this.elements = [];
		this.logmessages = [];
		
		this.build();
	},
	
	build: function () {
		var arrOfElements = $$('div.vf_votitaly-inline-rating');
		
		if ($type(arrOfElements) != 'array') {
			this.log('Parametri di inizializzazione errati!');
			return false;
		}
		if (!arrOfElements.length) {
			this.log('Nessun elemento di inizializzazione configurato!');
			return false;
		}

		// analisi degli elementi passati come parametro
		var _class = this;
		var container_fx = box_fx = [];
		arrOfElements.each(function (el) {
			var actual_el_id = el.getElement('div.vf_votitaly-get-id').get('text');
			
			var actual_id = el.id;

			var togglers = el.getElements('a.vf_votitaly-toggler');

			container_fx[actual_el_id] = new Fx.Morph (actual_id, {duration:1000, wait:false});
			box_fx[actual_el_id] = new Fx.Morph ($(actual_id).getElement('div.vf_votitaly-box'), {duration:1000, wait:false});
			// foreach star to click
			togglers.each(function(tog) {
				
				tog.addEvent('click', function (e) {
          var container_id = actual_id;
					var element_id = actual_el_id;
					container_fx[element_id].start({
						'opacity': 0.3
					});
					
					// increasing performance:
					$(container_id).getElement('div.vf_votitaly-box').set('html','<img src="'+_class.options.loadingimg+'" class="loading" /> '+_class.options.language.updating);
					
					new Request ({
						url: _class.options.submiturl, 
						method: 'post',
						data: 'task=vote&cid='+element_id+'&rating='+tog.get('text'),
						onComplete: function(jresponse){
							var json = JSON.decode (jresponse, true);
								var cont_el = $(container_id);
								// modifica width li.current-rating
								cont_el.getElement('li.vf_current-rating').setStyle('width', json.width);
								
								// opacity 1 su tutto il div
								container_fx[element_id].start({
									'opacity': 1,
									'background-color': '#fff'
								});
								// effetto sul box per ringraziamenti
								box_fx[element_id].start({'opacity': 0}).chain(function() {
									cont_el.getElement('div.vf_votitaly-box').set('html',
										(json.success ? _class.options.language.thanks : _class._getErrorString(json.return_code))
									);
									box_fx[element_id].start({'opacity': 1}); // visibile
									
								}).chain(function () {
									var func = function() {
										box_fx[element_id].start({'opacity': 0}).chain(function() {
											_class._update_voting_description(
													cont_el.getElement('div.vf_votitaly-box'),
													json.num_votes, // #totale voti
													json.average,		// media voti
													json.out_of			// massimo scala votazione
											);
											box_fx[element_id].start({'opacity': 1}); // visibile
										});
									}.delay((json.success ? 1000 : 4000));
								});
						}
					}).send();
				});
			});
		});
		
	},

	_update_voting_description: function (box_el, num_votes, average, out_of) {
		var string = this.options.star_description;

		string = string.replace(/{num_votes}/ig, num_votes)
							.replace(/{num_average}/ig, average)
							.replace(/{num_outof}/ig, out_of)
							.replace(/#VF_VOTES/ig, num_votes == 1 ? this.options.language.vote : this.options.language.votes )
							.replace(/#VF_AVERAGE/ig, this.options.language.average )
							.replace(/#VF_OUTOF/ig, this.options.language.outof );

		box_el.set('html', string);
		
	},

	_getErrorString: function (errno) {
		switch (errno) {
			case 1: return this.options.language.error1;
			case 2: return this.options.language.error2;
			case 3: return this.options.language.error3;
			case 4: return this.options.language.error4;
			case 5: return this.options.language.error5;
			default: return 'undefined';
		}
	},

	//-- error logs methods ---------------//
	log: function (string) {			
		this.logmessages.include(string);
	},
	showLogs: function () {
		this.logmessages.each(function (message) {
			console.log(message);
		});
	},
	hasLogs: function () {
		return this.logmessages.length > 0;
	},
	emptyLogs: function () {
		this.logmessages = [];
	}
});
VotitalyPlugin.implement(new Options);