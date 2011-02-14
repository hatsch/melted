/*
function refresh() {
//   jQuery('#melted_status').load('/melted/refresh #melted_status'); 

   jQuery('#melted_status').load('/melted/refresh #melted_status');
}
jQuery(document).ready(function(){
    refresh();
      setInterval ("refresh()",2000);
});
*/

// try with json, should be faster...
 
  var refresh_content = function(data) {
    jQuery('div.melted_status').html(data.data);
  }
 function refresh() {
  var data;  
    jQuery.ajax({
        type: 'GET',
        url: 'http://melted/melted/refresh',
        data: data,
        success: refresh_content,
        dataType: 'json'
      });
  }
 
  jQuery(document).ready(function() {
    refresh();
    setInterval  ("refresh()",2000);
  });
  
