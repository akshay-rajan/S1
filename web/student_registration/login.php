<html>
	<head>
		<title>Login</title>
	</head>
	<body>
		<h1>LOGIN</h1>
		<form action="home.php" method="post">
			KTU ID: <input type="text" name="ktuid"><br>
			PASSWORD: <input type="password" name="password"><br>
			<input type="submit" name="login" value="Login">
		</form>
		<div>
			Don't have an account? <a href="register.php">Register</a>
		</div>
	</body>
</html>

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
			$conn = mysqli_connect('localhost', 'root', '', 'registration');
			//$conn = mysqli_connect('localhost', '', '', 'registration');
			if(!$conn)
			{
				echo "Cannot connect";
			}
			else
			{
				$sql = "INSERT INTO users VALUES ('$ktuid', '$name', $age, '$gender', '$phone', $sem, $rollno, '$email', '$password')";
				$result = mysqli_query($conn, $sql);
				if ($result) {
					echo "<h2>Registered!</h2>";
				} else {
					echo "<h2>Cannot register!</h2>";
				}
				mysqli_close($conn);
			}
		}

	}
?>
