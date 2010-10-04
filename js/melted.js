function refresh() {
 jQuery('#melted_status').load('/melted/refresh #melted_status');
}
jQuery(document).ready(function(){
  refresh();
  setInterval ("refresh()",2000);
});
