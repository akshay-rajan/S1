<html>
	<head>
		<style>
			body {
				background-color: #F5F5F5;
				margin: 50px;
				display: flex;
				justify-content: center;
				text-align: center;
			}
			h1 {
				background-color: #FC5185;
				color: #f5f5f5;
			}
			table {
				width: 100%;
				margin: auto;
				text-align: left;
			}
			td, th {
				padding: 5px;
			}
			form input[type="submit"] {
				margin: auto;
				text-align: center;
				background-color: #FC5185;
                border-radius: 5px;
                border-color: #364F6B;
				width: 100%;
				height: 30px;
			}
			form input[type="text"], input[type="password"] {
				width: 100%;
			}
			.container {
				width: 30%;
			}
		</style>
	</head>
	<body>
		<div class="container">
			<h1>LOGIN</h1>
			<form action="home.php" method="post">
				<table>
					<tr>
						<th>KTU ID</th>
						<td><input type="text" name="ktuid"></td>
					</tr>	
					<tr>
						<th>Password</th>
						<td><input type="password" name="password"></td>
					</tr>
					<tr>
						<td colspan="2"><input type="submit" name="login" value="Login"></td>
					</tr>
				</table>
			</form>
			<div>
				Don't have an account? <a href="register.php">Register</a>
			</div>
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
			echo "<div><h2>Passwords do not match!</h2></div>";
		}
		else
		{
			$conn = mysqli_connect('localhost', 'root', '', 'registration');
			if(!$conn)
			{
				echo "Cannot connect";
			}
			else
			{
				$sql = "INSERT INTO users VALUES ('$ktuid', '$name', $age, '$gender', '$phone', $sem, $rollno, '$email', '$password')";
				$result = mysqli_query($conn, $sql);
				if ($result) {
					echo "<div><h2>Registered!</h2></div>";
				} else {
					echo "<div><h2>Cannot register!</h2></div>";
				}
				mysqli_close($conn);
			}
		}

	}
?>
		</div>
	</body>
</html>
