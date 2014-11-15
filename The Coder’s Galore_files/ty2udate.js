/**
 * @version	$Id: ty2udate.js 13 2011-04-28 07:08:24Z ty2u $
 * @package	mod_date2
 * @copyright	(C) Copyright 2011 Ryan Rhode, All rights reserved.
 * @license	GNU/GPL - See license.txt
 */
function listen(evnt,elem,func){if(elem.addEventListener)elem.addEventListener(evnt,func,false);else if(elem.attachEvent){var r=elem.attachEvent("on"+evnt,func);return r}}
