<?php
?>

<script type="text/javascript">
			jQuery(document).ready(function() {
				jQuery('.view-mca-airline-order-management tbody tr').click(function(event) {
					var tr = jQuery(this);
					var td = tr.find('td.views-field-id');
					if (td.length==0) {
						alert('views-field-id not found');
						return;
					}
          if(event.metaKey==true){
              window.open("<?php print url($_GET['q'].'/id') ?>/".replace('id', td.text().trim()));
          }else{
              window.location.href = "<?php print url($_GET['q'].'/id') ?>/".replace('id', td.text().trim());
          }
				});
        jQuery('.view-mca-airline-order-management tbody tr').css('cursor','pointer');

			});
		</script>