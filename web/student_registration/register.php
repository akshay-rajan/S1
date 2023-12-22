<html>
	<head>
		<style>
			body {
				font-family: Arial, Helvetica, sans-serif;
				background-color: #F5F5F5;
				margin: 20px;
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
			th, td {
				padding: 4px;
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
			form select {
				width: 100%;
			}
		</style>
	</head>
	<body>
		<div>
		<h1>REGISTER</h1>
		<form action="login.php" method="post" onsubmit="return validateForm()">
			<table>
				<tr>
					<th>KTU ID</th>
					<td><input type="text" name="ktuid" id="ktuid"><td>
				</tr>
				<tr>
					<th>Name</th>
					<td><input type="text" name="name" id="name"></td>
				</tr>
				<tr>
					<th>Age</th>
					<td><input type="text" name="age" id="age"></td>
				</tr>
				<tr>
					<th>Gender</th>
					<td><select name="gender" id="gender">
							<option value="none" selected disabled>Select</option>
							<option value="MALE">Male</option>
							<option value="FEMALE">Female</option>
						</select></td>
				</tr>
				<tr>
					<th>Phone Number</th>
					<td><input type="text" name="phone" id="phone"></td>
				</tr>
				<tr>
					<th>Semester</th>
					<td><input type="text" name="sem" id="sem"></td>
				</tr>	
				<tr>
					<th>Roll Number</th>
					<td><input type="text" name="rollno" id="rollno"></td>
				</tr>
				<tr>
					<th>E-Mail</th>
					<td><input type="text" name="email" id="email"></td>
				</tr>
				<tr>
					<th>Password</th>
					<td><input type="password" name="password" id="password"></td>
				</tr>
				<tr>
					<th>Re-Type Password</th>
					<td><input type="password" name="repassword" id="repassword"></td>
				</tr>
				<tr>
					<td colspan="2"><input name="register" type="submit" value="Register"></td>
				</tr>
			</table>
		</form>
		Already have an account? <a href="login.php">Login</a>
		</div>

		<script>
			// Form Validation
			function validateId() {
				let id = document.getElementById('ktuid').value;
				let idFormat = /TVE\d{2}\MCA-200\d$/;
				// Test the input against the regular expression
				let isValid = idFormat.test(id);
				if (!isValid) {
					alert("KTU ID is of invalid format!");
				}
				return isValid;
			}
			function validateName() {
				let name = document.getElementById('name').value;
				if (/^[a-zA-Z]+$/.test(name) && (name.length > 3)) {
					return true;
				}
				alert("Name invalid!");
				return false;
			}
			function validateAge() {
				let age = document.getElementById('age').value;
				if (/^\d+$/.test(age)) {
					return true;
				}
				alert("Age Invalid!");
				return false;
			}
			function validateGender() {
				let gender = document.getElementById('gender').value;
				if (gender !== "none") {
					return true;
				}
				alert("Please select a gender!");
				return false;
			}
			function validatePhone() {
				let phone = document.getElementById('phone').value;
				if (/^\d{10,11}$/.test(phone)) {
					return true;
				}
				alert("Phone number Invalid!");
				return false;
			}
			function validateSem() {
				let sem = document.getElementById('sem').value;
				if (/^[1-4]$/.test(sem)) {
					return true;
				}
				alert("Invalid Semester!");
				return false;
			}
			function validateRoll() {
				let roll = document.getElementById('rollno').value;
				if (/^[1-60]$/.test(roll)) {
					return true;
				}
				alert("Invalid Roll Number!");
				return false;
			}
			function validateEmail() {
				let email = document.getElementById('email').value;
				let emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
				if (emailRegex.test(email)) {
					return true;
				}
				alert("Invalid email format!");
				return false;
			}
			function validatePassword() {
				let password = document.getElementById('password').value;
				let confirmPassword = document.getElementById('repassword').value;

				// Password must contain at least 8 characters, one number, one letter, and one symbol
				let passwordRegex = /^(?=.*[A-Za-z])(?=.*\d)(?=.*[!@#$%^&*()_+])[A-Za-z\d!@#$%^&*()_+]{8,}$/;
				if (passwordRegex.test(password) && password === confirmPassword) {
					return true;
				}
				if (!passwordRegex.test(password))
					alert("Password must contain at least 8 characters, one number, one letter, and one symbol!");
				else 
					alert("Passwords donot match!");
				return false;
			}


			function validateForm() {
				if (validateId() && validateName() && validateAge() && validateGender() && validatePhone()
				 && validateSem() && validateRoll() && validateEmail() && validatePassword()) {
					return true;
				}
				return false;
			}
		</script>
	</body>
</html>
