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
			$home = $_POST['home'];
			$office = $_POST['office'];
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
