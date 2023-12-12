<?php 	
	session_start();
	$conn = mysqli_connect('localhost', 'root', '', 'registration');
	if(!$conn)
	{
		echo "Cannot connect";
	}
	else
	{
		if ($_SESSION['ktu_id']) {
			if ($_SESSION['ktu_id'] != 'teacher') {
				$ktu_id = $_SESSION['ktu_id'];
				$sql = "SELECT * FROM users WHERE ktu_id='$ktu_id'";
				$result = mysqli_query($conn, $sql);

				$row = mysqli_fetch_assoc($result);
				echo "
					<table border=1 align='center' width='60%'>
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
				echo "<h1>Welcome!</h1>";
			}	
		} else {
			echo "<h1>Welcome!</h1>";
		}
	}
?>

<?php
	$ktuid = $_POST['ktuid'];
	$password = $_POST['password'];
	
	$conn = mysqli_connect('localhost', 'root', '', 'registration');
	if ($_POST['login'])
	{
		// Student Details
		if ($ktuid == 'teacher' && $password == 'teacher') {
			$_SESSION['ktu_id'] = 'teacher';
			$sql = "SELECT * FROM users WHERE ktu_id !='$ktuid'";
			$result = mysqli_query($conn, $sql);
			echo "<table>
					<tr>
						<th>KTU ID</th>
						<th>NAME</th>
						<th>AGE</th>
						<th>GENDER</th>
						<th>PHONE</th>
						<th>SEMESTER</th>
						<th>ROLL NO</th>
						<th>EMAIL</th>
					</tr>";
			while ($row = mysqli_fetch_assoc($result)) {
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
					</tr>
				";
			}
			echo "</table>";
		} else {
			$q = "SELECT * FROM users WHERE ktu_id='$ktuid' AND password='$password'";
			$query = mysqli_query($conn, $q);
			if (mysqli_num_rows($query) > 0) {
				$_SESSION['ktu_id'] = $ktuid;
				$row = mysqli_fetch_assoc($query);
			 	echo "
					<table border=1 align='center' width='60%'>
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
		}
	}
	mysqli_close($conn);
?>
