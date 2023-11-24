<?php
	$n = $_POST['number'];
	
	function factorial($x) {
		if ($x == 0) {
			return 1;
		}
		return $x * factorial($x - 1);
	}
	echo "The factorial is ".factorial($n);
?>
