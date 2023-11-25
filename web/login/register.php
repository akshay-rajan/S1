<html>
	<head>
		<title>Register</title>
	</head>
	<body>
		<form action="" method="post">
			NAME: <input type="text" name="name"><br>
			E-MAIL: <input type="text" name="email"><br>
			PHONE NO: <input type="text" name="phone"><br>
			PASSWORD: <input type="password" name="password"><br>
			RE-TYPE PASSWORD: <input type="password" name="repassword">
			<input type="submit" value="Register">
		</form>

<?php
	$name=$_POST['name'];
	$email=$_POST['email'];
	$phone=$_POST['phone'];
	$password=$_POST['password'];
	$repassword=$_POST['repassword'];

	if($password!=$repassword) 
	{
		echo "Passwords do not match";
	}
	else
	{
		$conn = mysqli_connect('localhost', 'root', '', 'login');
		if(!$conn)
		{
			echo "Cannot connect";
		}
		else
		{
			$q = "INSERT INTO users (name, email, phone, password) VALUES ($name, $email, $phone, $password)";
			echo $q;	
			$query = mysqli_query($conn, $q);
			echo $q;
			if ($query) {
				echo "<h2>Registered!</h2>";
			} else {
				echo "<h2>Cannot register!</h2>";
			}
			mysqli_close($conn);
		}
	}
?>
	</body>
</html>

