<h1>Student Registration</h1>
<table style="position: fixed;right: 0px;top:15px;" cellpadding=5>
	<tr>
		<?php 
			session_start();
			if ($_SESSION['ktu_id'])
			echo "<td>Logged In: {$_SESSION['ktu_id']}</td>";
		?>
		<td>
			<form action="search.php" method="POST" target="home">
				<input type="text" name="ktu_id" placeholder="Search Using KTU ID">
				<input type="submit" name="search" value="Search"> 
			</form>
		</td>
		<td><a href="home.php" target="home">Home</a></td>
		<td><a href="register.php" target="home">Register</a></td>
		<td><a href="login.php" target="home">Login</a></td>
		<td><a href="logout.php" target="home">Logout</a></td>
		<td><a href="marks.php" target="home">Marks</a></td>
	</tr>
</table>

