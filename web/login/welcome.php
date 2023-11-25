<html>
	<body>
		<?php 
			session_start();
			echo "Welcome, ", $_SESSION['name'];
		?>
	</body>
</html>
