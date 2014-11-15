/** 
 *------------------------------------------------------------------------------
 * @package       T3 Framework for Joomla!
 *------------------------------------------------------------------------------
 * @copyright     Copyright (C) 2004-2013 JoomlArt.com. All Rights Reserved.
 * @license       GNU General Public License version 2 or later; see LICENSE.txt
 * @authors       JoomlArt, JoomlaBamboo, (contribute to this project at github 
 *                & Google group to become co-author)
 * @Google group: https://groups.google.com/forum/#!forum/t3fw
 * @Link:         http://t3-framework.org 
 *------------------------------------------------------------------------------
 */

 
var JASliderSupport = {
	inited: false,
	sid: null,
	refresh: false,
	
	initialize: function(){
		if(window.jasliderInst && window.jasliderInst.length && !JASliderSupport.inited){

			window.jasliderInst.each(function(inst){
				inst._ooptions = Object.clone(inst.options);
			});
			
			
			window.addEvent('resize', function(){
				clearTimeout(JASliderSupport.sid);
				JASliderSupport.refresh = true;
				JASliderSupport.sid = setTimeout(JASliderSupport.resize, 100);
			});
			
			JASliderSupport.resize();
			
			JASliderSupport.inited = true;
		}
	},
	resize: function(){
		window.jasliderInst.each(function(instance){

			var ooptions = instance._ooptions,
				options = instance.options,
				vars = instance.vars,
				ratio = vars.slider.setStyle('width', '').getWidth() / ooptions.mainWidth,
				nwidth = Math.floor(ooptions.mainWidth * ratio),
				nheight = Math.floor(ooptions.mainHeight * ratio),
				ntwidth = Math.floor(ooptions.thumbWidth * ratio),
				ntheight = Math.floor(ooptions.thumbHeight * ratio);
				
			options.mainWidth = nwidth;
			options.mainHeight = nheight;
			options.mainWidth = nwidth;
			options.thumbWidth = ntwidth;
			options.thumbHeight = ntheight;
			options.maskWidth = Math.floor(ooptions.maskWidth * ratio);
			options.maskHeigth = Math.floor(ooptions.maskHeigth * ratio);

			vars.mainWrap.setStyles({
				'width': nwidth,
				'height': nheight
			});

			vars.mainFrame.setStyles({
				'width': nwidth,
				'height': nheight
			});
			
			vars.mainItems.setStyles({
				'width': nwidth,
				'height': nheight
			});
			
			instance.initMasker();
			instance.initThumbAction();
			instance.initMainCtrlButton();
			instance.initProgressBar();

			if(JASliderSupport.refresh){
				setTimeout(function(){
					instance.next(true);
				}, 250);
			}

			clearTimeout(JASliderSupport.sid);
			JASliderSupport.sid = setTimeout(JASliderSupport.resize, (/iphone|ipod|android|ie|blackberry|fennec/).test(navigator.userAgent.toLowerCase()) ? 300 : 100);
		});

		JASliderSupport.refresh = false;
	}
};

(function($){
	$.fn.equalboxes = function(){
		var maxheight = 0,
			rowheight = 0,
			rowstart = 0,
			height = 0,
			boxes = [],
			top = 0,
			jel = null;

		//all equalheight (item will not align like a mess)
		this.each(function(){
			jel = $(this);
			height = jel.css({'height': '', 'min-height': ''}).removeClass('eq-first').height();

			if(height > maxheight){
				maxheight = height;
			}

			jel.data('orgHeight', height);

		}).css('min-height', maxheight);

		//per row equal-height
		this.each(function() {
			jel = $(this);
			height = jel.data('orgHeight');
			top = jel.position().top;

			if (rowstart != top) {
				boxes.length && $(boxes).css('min-height', rowheight + 1).eq(0).addClass('eq-first');

				// set the variables for the new row
				boxes.length = 0;
				rowstart = jel.position().top;
				rowheight = height;
				boxes.push(this);

			} else {
				boxes.push(this);
				if(height > rowheight){
					rowheight = height;
				}
			}
		});

		boxes.length && $(boxes).css('min-height', rowheight + 1).eq(0).addClass('eq-first');

		return this;
	};

	$.fn.liveeqboxs = function(){
		var elms = this,
			rzid = null,
			resize = function () {
				elms.equalboxes();
			};

		$(window).load(function(){
			//trigger one
			elms.equalboxes();

			clearTimeout(rzid);
			rzid = setTimeout(resize, 2000); //just in case something new loaded
		}).on('resize.eqb', function(){
			clearTimeout(rzid);
			rzid = setTimeout(resize, 200);
		});

		//trigger one
		elms.equalboxes();

		return this;
	};

})(jQuery);

(function($){
	$(window).load(function(){
		JASliderSupport.initialize();

		//equalheight
		var rzid = null,
			resize = function(){
				$('#t3-content, .t3-sidebar').equalHeight();

				clearTimeout(rzid);
				rzid = setTimeout(resize, 1500);
			};

		rzid = setTimeout(resize, 100);

		$(window).on('resize', function(){
			clearTimeout(rzid);
			rzid = setTimeout(resize, 200);
		});

		//equal height for megamenu
		$('.mega-dropdown-menu').each(function(){
			var jdropdown = $(this),
				odisplay = jdropdown.css('display');
				
			if(odisplay == 'none'){
				jdropdown.css('display', 'block');
			}
			
			jdropdown.find(' > .row-fluid > .mega-col-module').equalHeight();

			if(odisplay == 'none'){
				jdropdown.css('display', '');
			}
		});

		//add responsive for soccerway widget
		(function(){
			var jsswidgets = $('.soccerway-widget-ifm'),
				rzid = null,
				resize = function(){
					jsswidgets.each(function(){
						if(!$(this).is(':visible')){
							return;
						}

						this.width = $(this).parent().width();
						this.src = this.src.replace(/d=(\d+)/, 'd=' + this.width);
					});
				};

			$(window).on('resize', function(){
				clearTimeout(rzid);
				rzid = setTimeout(resize, 200);
			});

			rzid = setTimeout(resize, 100);
		})();
	});

	//fix validate.js error
	if(Browser.ie && Browser.version <= 8){
		Browser.Features.inputemail = false;
	}

})(jQuery);


(function($) {

	$(document).ready(function ($) {
		// back to top
		(function(){
			$('#back-to-top').on('click', function(){
				$('html, body').stop(true).animate({
					scrollTop: 0
				}, {
					duration: 800, 
					easing: 'easeInOutCubic',
					complete: window.reflow
				});

				return false;
			});
		})();

		//equalheight
		(function(){
    		$('#t3-content, .t3-sidebar').equalHeight();

    		//equal height for megamenu
			$('.mega-dropdown-menu').each(function(){
				var jdropdown = $(this),
					odisplay = jdropdown.css('display');

				if(odisplay == 'none'){
					jdropdown.css('display', 'block');
				}
				
				jdropdown.find(' > .row-fluid > .mega-col-module').equalHeight();

				if(odisplay == 'none'){
					jdropdown.css('display', '');
				}
			});
		})();
	});
})(jQuery);


/** 
 *------------------------------------------------------------------------------
 * @package   T3 Framework for Joomla!
 *------------------------------------------------------------------------------
 * @copyright Copyright (C) 2004-2013 JoomlArt.com. All Rights Reserved.
 * @license   GNU General Public License; http://www.gnu.org/licenses/gpl.html
 * @author    JoomlArt, JoomlaBamboo 
 *            If you want to be come co-authors of this project, please follow 
 *            our guidelines at http://t3-framework.org/contribute
 *------------------------------------------------------------------------------
 */

//jascrollbar
(function($){
	var javer = 1.0;
	if(window.jasb && window.jasb.version >= javer){
		return false;
	}
	
	var jasb = window.jasb || {};
	
	jasb.instances = jasb.instances || [];
	jasb.options = {
		axis: 'y', //( x || y ).
		wheel: 40,  //wheel amount.
		scroll: true, //enable or disable the mousewheel.
		lockscroll: true, //return scrollwheel to browser if there is no more content.
		size: 'auto', //set the size of the scrollbar to auto or a fixed number.
		sizethumb: 'auto', //set the size of the thumb to auto or a fixed number.	
		minthumb: 10 //the thumb is 10px in minimum.	
	};
	
	$.fn.jascrollbar = function(options) {
		if ( typeof options === 'string' ) {
			var args = Array.prototype.slice.call( arguments, 1 );

			this.each(function(){
				var instance = $.data( this, 'jascrollbar' );
				if (!instance || !$.isFunction( instance[options] )) {
					return;
				}
				
				// apply method
				instance[ options ].apply( instance, args );
			});
			
		} else {
			this.each(function() {
				var instance = $.data(this, 'jascrollbar');
				if ( instance ) {
					instance.update();
				} else {
					$.data(this, 'jascrollbar', new jacsb(this, options));
				}
			});
		}
		
		return this;
	};
	
	function jacsb(root, options){
		this.vars = {
			root: $(root),
			options: $.extend({}, jasb.options, options)
		};
		this.initialize();
		return this;
	}
	
	jacsb.prototype = {
		initialize: function() {
			var vars = this.vars,
				options = vars.options,
				root = vars.root;
				
			vars.viewport = root.find('.viewport');
			vars.content = root.find('.overview');
			vars.scrollbar = root.find('.scrollbar');
			vars.track = vars.scrollbar.find('.track');
			vars.thumb = vars.scrollbar.find('.thumb');
			vars.xaxis = options.axis == 'x';
				
			vars.dir = vars.xaxis ? 'left' : 'top';
			vars.size = vars.xaxis ? 'Width' : 'Height';
			vars.imove = 0;
			vars.itouch = ('ontouchstart' in window) || window.DocumentTouch && document instanceof DocumentTouch;
			vars.estart = vars.itouch ? 'touchstart' : 'mousedown';
			vars.emove = vars.itouch ? 'touchmove' : 'mousemove';
			vars.eend = vars.itouch ? 'touchend' : 'mouseup';
			vars.ecancel = vars.itouch ? 'touchcancel' : 'mouseup';
			vars.iscroll = 0;
			vars.ipstart = 0;
			vars.istart = 0;
			vars.inow = 0;
			
			vars.start = $.proxy(this.start, this);
			vars.end = $.proxy(this.end, this);
			vars.drag = $.proxy(this.drag, this);
			vars.wheel = $.proxy(this.wheel, this);
		
			this.update();
			this.addevents();
		},
		
		update: function(pos){
			var vars = this.vars,
				options = vars.options;
				
			vars.vpsize = vars.viewport[0]['offset' + vars.size];
			vars.ctsize = vars.content[0]['scroll' + vars.size];
			vars.sbsize = vars.ctsize - vars.vpsize;
			vars.cratio = vars.vpsize / vars.ctsize;
			vars.hasbar = vars.cratio < 1;
			
			if(vars.hasbar){
				vars.trsize = options.size == 'auto' ? vars.vpsize : options.size;
				vars.thsize = Math.min(vars.trsize, Math.max(options.minthumb, ( options.sizethumb == 'auto' ? (vars.trsize * vars.cratio) : options.sizethumb )));
				vars.stsize = vars.trsize - vars.thsize;
				vars.tratio = vars.sbsize / vars.stsize;
				vars.iscroll = (pos == 'relative' && vars.hasbar) ? Math.min(vars.sbsize, Math.max(0, vars.iscroll)) : 0;
				vars.iscroll = (pos == 'bottom' && vars.hasbar) ? vars.sbsize : isNaN(parseInt(pos)) ? vars.iscroll : parseInt(pos);
				vars.iscroll = Math.min(vars.sbsize, Math.max(0, vars.iscroll));

				vars.thumb.css(vars.dir, vars.iscroll / vars.tratio);
				vars.content.css('margin-' + vars.dir, -vars.iscroll);
				vars.istart = vars.thumb.offset()[vars.dir];
				
				var prop = vars.size.toLowerCase();
				vars.scrollbar.css(prop, vars.trsize);
				vars.track.css(prop, vars.trsize);
				vars.thumb.css(prop, vars.thsize);
			}
			
			vars.scrollbar.toggleClass('enable', vars.hasbar);
		},
		
		togglesbar: function(tg){
			var vars = this.vars;
			if(!vars.scrollbar.hasClass('enable')){
				return false;
			};
			
			if(tg){
				vars.scrollbar.fadeIn();
			} else {
				vars.scrollbar.fadeOut();
				vars.thumb.css(vars.dir, 0);
				vars.content.css('margin-' + vars.dir, 0);
			}
		},
	
		addevents: function(){
			var inst = this,
				vars = this.vars,
				options = vars.options;
			
			
			if(vars.itouch){
				vars.thumb[0].ontouchstart = function(e){
					e.preventDefault();
					vars.mode = 0;
					vars.imove = 0;
					inst.start(e.touches[0]);
					
					return false;
				};
				
				vars.content[0].ontouchstart = function(e){
					e.preventDefault();
					vars.mode = 1;
					vars.imove = 0;
					inst.start(e.touches[0]);
					
					return false;
				};
			} else {
				vars.thumb.on('mousedown', vars.start)
			}
			
			if(options.scroll && window.addEventListener){
				vars.root[0].addEventListener('DOMMouseScroll', vars.wheel, false);
				vars.root[0].addEventListener('mousewheel', vars.wheel, false);
			}
			else if(options.scroll){
				vars.root[0].onmousewheel = vars.wheel;
			}
		},
		
		start: function(e){
			var inst = this,
				vars = this.vars,
				pos = parseInt(vars.thumb.css(vars.dir));
			
			if(vars.mode == 1){
				pos = parseInt(vars.content.css('margin-' + vars.dir));
			}
			
			vars.istart = vars.options.xaxis ? e.pageX : e.pageY;
			vars.ipstart = isNaN(pos) ? 0 : pos;
			
			if(vars.itouch){
				document.ontouchmove = function(me){					
					me.preventDefault();
					inst.drag(me.touches[0]);
				};
				vars.thumb[0].ontouchend = document.ontouchend = function(me){
					inst.end(me);
				};
			} else {
				$(document).on('mousemove',  vars.drag).on('mouseup', vars.end);
				vars.thumb.on('mouseup', vars.end);
				vars.scrollbar.addClass('dragging');
			}
			
			return false;
		},
		
		wheel: function(e){
			var vars = this.vars;
			
			if(!(vars.cratio >= 1 )){
				var e = e || window.event,
					idelta = e.wheelDelta ? e.wheelDelta /120 : -e.detail /3;
				
				vars.iscroll -= idelta * vars.options.wheel;
				vars.iscroll = Math.min(vars.sbsize, Math.max(0, vars.iscroll));
				
				vars.thumb.css(vars.dir, vars.iscroll / vars.tratio);
				vars.content.css('margin-' + vars.dir, -vars.iscroll);

				if( vars.options.lockscroll || ( vars.iscroll !== vars.sbsize && vars.iscroll !== 0 )){
					e = $.event.fix(e);
					e.preventDefault();
				}
			}
		},
		
		end: function(e){
			var vars = this.vars;
			
			if(vars.itouch){
				document.ontouchmove = document.ontouchend = vars.thumb[0].ontouchend = null;
			}else{
				$(document).off('mousemove', vars.drag).off('mouseup', vars.end);
				vars.thumb.off('mouseup', vars.end);
				vars.scrollbar.removeClass('dragging');
			}
			
			if(vars.itouch && !vars.imove){
				var ce = e.changedTouches[0],
					target = ce.target;
				
				while (target.nodeType != 1){
					target = target.parentNode;
				}

				if (target.tagName != 'SELECT' && target.tagName != 'INPUT' && target.tagName != 'TEXTAREA') {
					var ev = document.createEvent('MouseEvents');
					ev.initMouseEvent('click', true, true, e.view, 1,
						ce.screenX, ce.screenY, ce.clientX, ce.clientY,
						e.ctrlKey, e.altKey, e.shiftKey, e.metaKey,
						0, null);
					ev._fake = true;
					target.dispatchEvent(ev);
				}
			}
			
			return false;
		},
		
		drag: function(e){
			var vars = this.vars;
			vars.imove = 1;
			if(!(vars.cratio >= 1)){
				if(vars.mode == 1){
					vars.iscroll = -Math.min(0, Math.max(-vars.sbsize, (vars.ipstart + ((vars.xaxis ? e.pageX : e.pageY) - vars.istart))));
					vars.inow = vars.iscroll / vars.tratio;
				}else {
					vars.inow = Math.min(vars.stsize, Math.max(0, (vars.ipstart + ((vars.xaxis ? e.pageX : e.pageY) - vars.istart))));
					vars.iscroll = vars.inow * vars.tratio;
				}
				
				vars.content.css('margin-' + vars.dir, -vars.iscroll);
				vars.thumb.css(vars.dir, vars.inow);
			}
			
			return false;
		},
		
		options: function(opts){
			$.extend(this.vars.options, opts);
		}
	};
})(jQuery);

//
(function($){
	$(document).ready(function(){

		//initilized affix
		(function(){
			var wnd = $(window),
				mainnav = $('#t3-mainnav'),
				sidebar = $('.sidebar-affix'),
				inset = $('.t3-inset');

			if((('ontouchstart' in window) || window.DocumentTouch && document instanceof DocumentTouch) && (inset.offset().top > $(window).height() / 2)) {
				return false;
			}
	
			sidebar.css('position', 'static');
			inset.css('position', 'static');
			$(document.body).css('min-height', Math.max($(window).height(), 
				inset.length ? inset.offset().top + 80 + Math.min($(window).height(), inset.height()) : 0, 
				sidebar.length ? sidebar.offset().top + 80 + sidebar.height() : 0));
			sidebar.css('position', '');
			inset.css('position', '');	

			if(sidebar.length){
				var sidebarprev = sidebar.prev();
				if(!sidebarprev.length){
					sidebarprev = sidebar.parent();
				}

				sidebar.affix({
					offset: {
						top: function () { 
							return sidebarprev.offset().top + sidebarprev.outerHeight(true) - 80
						}
					}
				});
			}

			if(inset.length){
			
				var insetprev = inset.prev();

				if(!insetprev.length){
					insetprev = inset.parent();
				}

				inset.affix({
					offset: {
						top: function () {
							return insetprev.offset().top - 80
						}
					}
				});
			}

			if(sidebar.length || inset.length){
				var rzid = null,
				resize = function(){
					sidebar.width(sidebarprev && sidebarprev.width() ? sidebarprev.width() : sidebar.parent().width());
					inset.width(insetprev && insetprev.width() ? insetprev.width() : inset.parent().width());

					$(window).trigger('scroll.affix.data-api');
				};

				wnd.on('resize orientationchange', function(){
					clearTimeout(rzid);
					$(window).trigger('scroll.affix.data-api');
					rzid = setTimeout(resize, 200);
				});

				resize();
			}
		})();
		
		//initilized infinitescroll
		(function(){
			var itemSelector = '.items-row',
				contentSelector = '.infinitescroll',
				infinitescroll = $('.infinitescroll');
			
			if(!infinitescroll.length){
				itemSelector = '.itemContainer';
				contentSelector = '#k2Container .itemList';
				infinitescroll = $(contentSelector).length ? $('#k2Container') : {};
			}

			if(!infinitescroll.length){
				itemSelector = '.userItemView';
				contentSelector = '#k2Container .userItemList';
				infinitescroll = $(contentSelector).length ? $('#k2Container') : {};
			}
			
			if(!infinitescroll.length){
				itemSelector = '.tagItemView';
				contentSelector = '#k2Container .tagItemList';
				infinitescroll = $(contentSelector).length ? $('#k2Container') : {};
			}

			if(!infinitescroll.length){
				return false;
			}

			var pathObject = {
				init: function(){
					this.path = ($('#page-next-link').attr('href') || '');
					var match = this.path.match(/((page|limitstart|start)[=-])(\d*)(&*)/i);
					if(match){
						this.type = match[2].toLowerCase();
						this.number = match[3];
						this.limit = this.type == 'page' ? 1 : this.number;
						this.number = this.type == 'page' ? this.number : 1;
					} else {
						this.type = 'unk';
						this.number = 2;
						this.path = this.path + (this.path.indexOf('?') == -1 ? '?' : '') + 'start=';
					}

					var urlparts = this.path.split('#');
					if(urlparts[0].indexOf('?') == -1){
						urlparts[0] += '?tmpl=component';
					} else {
						urlparts[0] += '&tmpl=component';
					}

					this.path = urlparts.join('#');
				},
				
				join: function(){
					if(pathObject.type == 'unk'){
						return pathObject.path + pathObject.number++;
					} else{
						return pathObject.path.replace(/((page|limitstart|start)[=-])(\d*)(&*)/i, '$1' + (pathObject.limit * pathObject.number++) + '$4');
					}
				}
			};
			pathObject.init();


			infinitescroll.infinitescroll({
				loading: {
					finished: undefined,
					finishedMsg: T3JSVars.finishedMsg,
					img: T3JSVars.tplUrl + '/images/ajax-load.gif',
					msg: null,
					msgText: T3JSVars.msgText,
					selector: null,
					speed: 'fast',
					start: undefined
				},
				state: {
					isDuringAjax: false,
					isInvalidPage: false,
					isDestroyed: false,
					isDone: false, // For when it goes all the way through the archive.
					isPaused: false,
					currPage: 0
				},
				debug: false,
				behavior: undefined,
				binder: $(window), // used to cache the selector for the element that will be scrolling
				nextSelector: '#page-next-link',
				navSelector: '#page-nav',
				contentSelector: contentSelector, // rename to pageFragment
				extraScrollPx: 150,
				itemSelector: itemSelector,
				animate: false,
				pathParse: pathObject.join,
				dataType: 'html',
				appendCallback: true,
				bufferPx: 350,
				errorCallback: function () { },
				infid: 0, //Instance ID
				pixelsFromNavToBottom: undefined,
				path: pathObject.join, // Can either be an array of URL parts (e.g. ["/page/", "/"]) or a function that accepts the page number and returns a URL
				prefill: false, // When the document is smaller than the window, load data until the document is larger or links are exhausted
				maxPage: undefined // to manually control maximum page (when maxPage is undefined, maximum page limitation is not work)
			}, function(){
				if(typeof DISQUSWIDGETS != 'undefined'){
					DISQUSWIDGETS.getCount();
				} else if(typeof disqus_shortname != 'undefined') {
					$.getScript('http://'+disqus_shortname+'.disqus.com/count.js');
				}
			});

		})();


		//initlized mega-dim
		(function(){

			var dim = $('<div class="mega-dim"></div>').appendTo(document.body),
				btnnav = $('.btn-navbar:first'),
				retain = [];

			$('#t3-mainnav .nav > li').hover(function(event) {
				if(btnnav.css('display') == 'none' || $(this).closest('.nav').parent().hasClass('head-social')){		
					if($.inArray(this, retain) == -1){
						retain.push(this);
					}
					clearTimeout ($(this).data('dimTimeout'));
					dim.addClass('active');					
				}
			},
			function(event) {
				if(dim.hasClass('active')){
					var that = this;
					$(this).data('dimTimeout', 
						setTimeout(function(){
							retain = $.grep(retain, function(item){
								return item != that;
							});

							if(retain.length <= 0){
								dim.removeClass('active');
							}

						}, 100));
				}
			});

			dim.on('click', function(){
				$(document).trigger('hidesub');
				retain.length = 0;
				dim.removeClass('active');
			});
		
		})();

		//initilized scrollbar
		(function(){

			var sid = null,
				scrollbar = $('.t3-inset.scrollcontainer'),
				overview = scrollbar.find('.overview:first'),
				viewport = scrollbar.find('.viewport:first'),

				resize = function(){
					var	wheight =  Math.min(overview.height(), Math.max($(window).height() - 80));
	
					viewport.css('height', wheight);
					
					scrollbar.jascrollbar('options', {
						size: wheight
					}).jascrollbar('update', 'relative');
				};

			viewport.after('<div class="scrollbar"><div class="track"><div class="thumb"><div class="end"></div></div></div></div>');
			viewport.css('height', Math.min(overview.height(), $(window).height() - 80));
			scrollbar.find('.scrollbar').css('top', viewport.prev().outerHeight(true));
			scrollbar.addClass('scrollcontainer').jascrollbar();

			$(window).on('resize.sbar', function(){
				clearTimeout(sid);
				sid = setTimeout(resize, 500);
			}).trigger('resize.sbar');

			$(window).load(function(){
				var active = overview.find('li.active .mod-articles-category-title, .mod-articles-category-title.active');
				if(!active.length){
					active = overview.find('li.active .moduleItemTitle, .moduleItemTitle.active');
				}

				scrollbar.jascrollbar('update', active.length ? (active.offset().top - overview.offset().top) : 'relative');
			});

		})();
	});

})(jQuery);

