<html>
	<head>
		<title>Job Application</title>
	</head>
	<body>
		<?php
			$name = $_POST['name'];
			$age = $_POST['age'];
			$email = $_POST['email'];
			
			$mal = $_POST['mal'];
			$eng = $_POST['hin'];
			$hin = $_POST['hin'];
			$lang = "";
			if (isset($mal)) {
				$lang .= "Malayalam ";
			} if (isset($eng)) {
				$lang .= " English ";
			} if (isset($hin)) {
				$lang .= " Hindi";
			}
			
			$home = $_POST['home'];
			$office = $_POST['office'];
			
			$pass = $_POST['password'];
			$pass_re = $_POST['password-re'];
			$security_qn = $_POST['sec'];
			$security_ans = $_POST['sec-ans'];
			
			if ($pass != $pass_re) {
				echo "<h1>Passwords donot match! <a href='forms.php'>Click here</a> to re-apply!</h1>";
			} else {
				// Add user to the database
				$conn = mysqli_connect('localhost', 'root', '', 'job_application');
				if (!$conn) {
					echo "Cannot connect to the database!<br>";
				} else {
					$q = "INSERT INTO applicants (name, age, email, languages, phone_home, phone_office, password, security_qn, security_ans) VALUES ('$name', $age, '$email', '$lang', '$home', '$office', '$pass', '$security_qn', '$security_ans')";
					$query = mysqli_query($conn, $q);
					if ($query) {
						echo "Applied successfully!";
					}
				}
				mysqli_close($conn);
			}

		?>
		<table border=1 align="center" width="60%">
			<tr>
				<th colspan="2">Registration Form</th>
			</tr>
			<tr>
				<td>Name</td>
				<td>
					<?php 
						echo $name;
					?>
				</td>
			</tr>
			<tr>
				<td>Age</td>
				<td>
					<?php 
						echo $age;
					?>				
				</td>
			</tr>
			<tr>
				<td>Email id</td>
				<td>
					<?php 
						echo $email;
					?>
				</td>
			</tr>
			<tr>
				<td>Languages Known</td>
				<td>
					<?php 						
						echo $lang;
					?>
				</td>
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
							<td>
								<?php 
									echo $home;
								?>
							</td>
							<td>
								<?php 
									echo $office;
								?>
							</td>
						</tr>		
					</table>
				</td>
			</tr>
		</table>	
	</body>
<html>
