<body>
	<h1>Welcome!</h1>
</body>

<?php
	$ktuid = $_POST['ktuid'];
	$password = $_POST['password'];
	
	$conn = mysqli_connect('localhost', 'root', '', 'registration');
	if(!$conn)
	{
		echo "Cannot connect";
	}
	else
	{
		if ($_POST['login'])
		{
				// Student Details
				$q = "SELECT * FROM users WHERE ktu_id='$ktuid' AND password='$password'";
				$query = mysqli_query($conn, $q);
					if (mysqli_num_rows($query) > 0) {
				    	$row = mysqli_fetch_assoc($query);
				     	echo "
							<table border=1 align='center'>
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
			mysqli_close($conn);
		}
	}
?>
