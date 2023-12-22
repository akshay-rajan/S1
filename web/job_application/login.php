<html>
	<head><title>Login</title></head>
	<body>
		<form action="" method="post">
			Name:<input type="text" name="name">
			Password:<input type="password" name="password">
			<input type="submit" value="Submit">
		</form>
		<?php 
			$name = $_POST['name'];
			$password = $_POST['password'];
			$conn = mysqli_connect('localhost', 'root', '', 'job_application');
			if (!$conn) {
				echo "Cannot connect to the database!<br>";
			} else {
				$q = "SELECT * FROM applicants WHERE name='$name' AND password='$password'";
			 	$query = mysqli_query($conn, $q);
			 	if ($query) {
			 		$row = mysqli_fetch_assoc($query);
			 		echo "
			 		<h1>Logged In as {$row['name']}</h1>
			 		<table border=1 align='center' width='60%'>
			 			<tr>
			 				<th colspan='2'>Registration Form</th>
			 			</tr>
			 			<tr>
			 				<td>Name</td>
			 				<td>{$row['name']}</td>
			 			</tr>
			 			<tr>
			 				<td>Age</td>
			 				<td>{$row['age']}</td>
			 			</tr>
			 			<tr>
			 				<td>Email id</td>
			 				<td>{$row['email']}</td>
			 			</tr>
			 			<tr>
			 				<td>Languages Known</td>
			 				<td>{$row['lang']}</td>
			 			</tr>
			 			<tr>
			 				<td>Phone number</td>
			 				<td>
			 					<table border=1>
			 						<tr>
			 							<th>Home</th>
			 							<th>Office</th>
			 						</tr>
			 						<tr>
			 							<td>{$row['home']}</td>
			 							<td>{$row['office']}</td>
			 						</tr>		
			 					</table>
			 				</td>
			 			</tr>
			 		</table>";
			 	} else {
			 		echo "<h2>Cannot Login! Try again.</h2>";
			 	}
			 }
			 mysqli_close($conn);	
		?>
	</body>
</html>

