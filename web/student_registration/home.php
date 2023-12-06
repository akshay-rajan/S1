<body>
	<h1>Welcome!</h1>
</body>

<?php
	$username = $_POST['username'];
	$password = $_POST['password'];
	
	// $conn = mysqli_connect('localhost', 'root', '', 'registration');
	$conn = mysqli_connect('localhost', '', '', 'registration');
	if(!$conn)
	{
		echo "Cannot connect";
	}
	else
	{
		if ($_POST['submit'])
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
