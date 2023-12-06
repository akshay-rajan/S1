<html>
	<head>
		<title>Register</title>
	</head>
	<body>
		<h1>REGISTER</h1>
		<form action="login.php" method="post">
			KTU ID: <input type="text" name="ktuid"><br> 
			NAME: <input type="text" name="name"><br>
			AGE: <input type="text" name="age"><br>
			GENDER: <select name="gender">
						<option value="none" selected disabled>Select</option>
						<option value="MALE">Male</option>
						<option value="FEMALE">Female</option>
					</select></br>
			PHONE NO: <input type="text" name="phone"><br>
			SEMESTER: <input type="text" name="sem"><br>
			ROLL NO: <input type="text" name="rollno"><br>
			E-MAIL: <input type="text" name="email"><br>
			PASSWORD: <input type="password" name="password"><br>
			RE-TYPE PASSWORD: <input type="password" name="repassword">
			<input name="register" type="submit" value="Register">
		</form>
		<div>
			Already have an account? <a href="login.php">Login</a>
		</div>
	</body>
</html>
