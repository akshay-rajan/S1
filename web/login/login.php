<html>
	<head>
		<title>Login</title>
	</head>
	<body>
		<h1>LOGIN</h1>
		<form action="" method="post">
			USERNAME: <input type="text" name="username"><br>
			PASSWORD: <input type="password" name="password"><br>
			<input type="submit" name="sub" value="Login">
		</form>
		<div>
			Don't have an account? <a href="register.php">Register</a>
		</div>
<?php
	session_start();
	$email = $_POST['username'];
	$password = $_POST['password'];
	
	$conn = mysqli_connect('localhost', 'root', '', 'login');
	if(!$conn)
	{
		echo "Cannot connect";
	}
	else
	{
		if ($_POST['sub'])
		{
			$q = "SELECT * FROM users WHERE email='$email' AND password='$password'";
			$query = mysqli_query($conn, $q);
		 		//$row = mysqli_fetch_assoc($query);
				if (mysqli_num_rows($query) > 0) { 
		        	$row = mysqli_fetch_assoc($query);
		            $_SESSION["name"] = $row['name'];         
					header('Location:welcome.php');
				}
		        else {
					echo "Invalid username or password";
				}
		
			mysqli_close($conn);
		}
	}
?>
	</body>
</html>
