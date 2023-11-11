<html>
	<head>
		<title>Job Application</title>
	</head>
	<body>
		<table border=1 align="center" width="60%">
			<tr>
				<th colspan="2">Registration Form</th>
			</tr>
			<tr>
				<td>Name</td>
				<td>
					<?php 
						$name = $_POST['name'];
						echo $name;
					?>
				</td>
			</tr>
			<tr>
				<td>Age</td>
				<td>
					<?php 
						$age = $_POST['age'];
						echo $age;
					?>				
				</td>
			</tr>
			<tr>
				<td>Email id</td>
				<td>
					<?php 
						$email = $_POST['email'];
						echo $email;
					?>
				</td>
			</tr>
			<tr>
				<td>Languages Known</td>
				<td>
					<?php 
						$mal = $_POST['mal'];
						$eng = $_POST['hin'];
						$hin = $_POST['hin'];
						
						if (isset($mal)) {
							echo "Malayalam";
						}
						if (isset($eng)) {
							echo " English ";
						}
						if (isset($hin)) {
							echo " Hindi ";
						}
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
									$home = $_POST['home'];
									echo $home;
								?>
							</td>
							<td>
								<?php 
									$office = $_POST['office'];
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
