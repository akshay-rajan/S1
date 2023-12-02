<html>
	<head>
		<title>Login</title>
	</head>
	<body>
		<h1>LOGIN</h1>
		<form action="home.php" method="post">
			USERNAME: <input type="text" name="username"><br>
			PASSWORD: <input type="password" name="password"><br>
			<input type="submit" name="sub" value="Login">
		</form>
		<div>
			Don't have an account? <a href="register.php">Register</a>
		</div>
	</body>
</html>
<?php
	$username = $_POST['username'];
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
			$q = "SELECT * FROM users WHERE email='$username' AND password='$password'";
			$query = mysqli_query($conn, $q);
				if (mysqli_num_rows($query) > 0) {
		        	$row = mysqli_fetch_assoc($query);
		         	echo "
						<table>
							<tr>
								<td>Name</td>
								<td>{$row['name']}</td>	
							</tr>
							<tr>
								<td>Email</td>
								<td>{$row['email']}</td>	
							</tr>
							<tr>
								<td>Phone Number</td>
								<td>{$row['phone']}</td>	
							</tr>
						</table>"; 
				}		
			mysqli_close($conn);
		}
	}
?>

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
			$q = "INSERT INTO users (name, email, phone, password) VALUES ('$name', '$email', '$phone', '$password')";
			$query = mysqli_query($conn, $q);
			if ($query) {
				echo "<h2>Registered!</h2>";
			} else {
				echo "<h2>Cannot register!</h2>";
			}
			mysqli_close($conn);
		}
	}
?>
