<body>
	<h1>Welcome!</h1>
</body>

<?php
	$ktuid = $_POST['ktuid'];
	$password = $_POST['password'];
	
	$conn = mysqli_connect('localhost', 'root', '', 'registration');
	// $conn = mysqli_connect('localhost', '', '', 'registration');
	if(!$conn)
	{
		echo "Cannot connect";
	}
	else
	{
		if ($_POST['login'])
		{/*
			if ($ktuid = '001' && $password = '111')
			{
				// If the user is the teacher
				echo "ktu id: {$ktuid}, password: {$password}";
				$q = "SELECT * FROM users WHERE ktu_id!='001'";
				$query = mysqli_query($conn, $q);
				echo "<table border=1>
						<tr>
							<td>KTU ID</td>
							<td>Name</td>
							<td>Age</td>
							<td>Gender</td>
							<td>Phone Number</td>
							<td>Semester</td>
							<td>Roll No</td>
							<td>Email</td>
						</tr>";
				while ($row = mysqli_fetch_assoc($query)){
					echo "
							<tr>
								<td>{$row['ktu_id']}</td>
								<td>{$row['name']}</td>	
								<td>{$row['age']}</td>	
								<td>{$row['gender']}</td>	
								<td>{$row['phone']}</td>	
								<td>{$row['sem']}</td>
								<td>{$row['roll_no']}</td>	
								<td>{$row['email']}</td>	
							</tr>";
				}
				echo "</table>";
			}
			else 
			{*/
				// Student
				$q = "SELECT * FROM users WHERE ktu_id='$ktuid' AND password='$password'";
				$query = mysqli_query($conn, $q);
					if (mysqli_num_rows($query) > 0) {
				    	$row = mysqli_fetch_assoc($query);
				     	echo "
							<table border=1>
								<tr>
									<td>KTU ID</td>
									<td>{$row['ktu_id']}</td>	
								</tr>
								<tr>
									<td>Name</td>
									<td>{$row['name']}</td>	
								</tr>
								<tr>
									<td>Age</td>
									<td>{$row['age']}</td>	
								</tr>
								<tr>
									<td>Gender</td>
									<td>{$row['gender']}</td>	
								</tr>
								<tr>
									<td>Phone Number</td>
									<td>{$row['phone']}</td>	
								</tr>
								<tr>
									<td>Semester</td>
									<td>{$row['sem']}</td>	
								</tr>
								<tr>
									<td>Roll No</td>
									<td>{$row['roll_no']}</td>	
								</tr>
								<tr>
									<td>Email</td>
									<td>{$row['email']}</td>	
								</tr>
							</table>";
					} else {
						echo "User not found!";
					}
				//}
			mysqli_close($conn);
		}
	}
?>
