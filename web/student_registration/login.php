<html>
	<head>
		<title>Login</title>
	</head>
	<body>
		<h1>LOGIN</h1>
		<form action="home.php" method="post">
			KTU ID: <input type="text" name="ktuid"><br>
			PASSWORD: <input type="password" name="password"><br>
			<input type="submit" name="submit" value="Login">
		</form>
		<div>
			Don't have an account? <a href="register.php">Register</a>
		</div>
	</body>
</html>
<?php	
	// $conn = mysqli_connect('localhost', 'root', '', 'login');
	// $conn = mysqli_connect('localhost', '', '', 'registration');
	// if(!$conn)
	// {
	// 	echo "Cannot connect";
	// }
	// else
	// {
	// 	if ($_POST['register'])
	// 	{
	// 		$q = "SELECT * FROM users WHERE email='$username' AND password='$password'";
	// 		$query = mysqli_query($conn, $q);
	// 			if (mysqli_num_rows($query) > 0) {
	// 	        	$row = mysqli_fetch_assoc($query);
	// 	         	echo "
	// 					<table>
	// 						<tr>
	// 							<td>Name</td>
	// 							<td>{$row['name']}</td>	
	// 						</tr>
	// 						<tr>
	// 							<td>Email</td>
	// 							<td>{$row['email']}</td>	
	// 						</tr>
	// 						<tr>
	// 							<td>Phone Number</td>
	// 							<td>{$row['phone']}</td>	
	// 						</tr>
	// 					</table>"; 
	// 			}		
	// 		mysqli_close($conn);
	// 	}
	// } 
?>

<?php
	if ($_POST['register']) {
		$ktuid = $_POST['ktuid'];
		$name=$_POST['name'];
		$age=$_POST['age'];
		$gender=$_POST['gender'];
		$phone=$_POST['phone'];
		$sem=$_POST['sem'];
		$rollno=$_POST['rollno'];
		$email=$_POST['email'];
		$password=$_POST['password'];
		$repassword=$_POST['repassword'];

		if($password!=$repassword) 
		{
			echo "Passwords do not match";
		}
		else
		{
			// $conn = mysqli_connect('localhost', 'root', '', 'login');
			$conn = mysqli_connect('localhost', '', '', 'registration');
			if(!$conn)
			{
				echo "Cannot connect";
			}
			else
			{
				$sql = "INSERT INTO users VALUES ('$ktuid', '$name', $age, '$gender', '$phone', $sem, $rollno, '$email', '$password')";
				$result = mysqli_query($conn, $sql);
				if ($query) {
					echo "<h2>Registered!</h2>";
				} else {
					echo "<h2>Cannot register!</h2>";
				}
				mysqli_close($conn);
			}
		}

	}
?>
