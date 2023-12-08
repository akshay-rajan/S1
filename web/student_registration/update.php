<h1>Add or Update Marks</h1>
<form action="" method="POST">
    <?php 
        $conn = mysqli_connect('localhost', 'root', '', 'registration');
        if (!$conn) {
            echo "Cannot connect!";
        } else {

            $ktu_id = $_POST['ktu_id'];
            $sql = "SELECT * FROM marks WHERE ktu_id='$ktu_id'";
            $result = mysqli_query($conn, $sql);
            $row = mysqli_fetch_assoc($result);
            if ($result) {
                if (mysqli_num_rows($result) == 0) {
                    // Fresh entry of marks
                    echo "
                        <input type='hidden' name='ktu_id' value='{$ktu_id}'>
                        Series 1: <input type='text' name='series1'><br>
                        Series 2: <input type='text' name='series2'><br>
                        Assignment 1: <input type='text' name='assignment1'><br>
                        Assignment 2: <input type='text' name='assignment2'><br>
                        Attendance : <input type='text' name='attendance'><br>
                        <input type='submit' value='Add Marks' name='add'>
                    ";

                } else {
                    // Marks already entered, requires updation
                    echo "
                        <input type='hidden' name='ktu_id' value='{$ktu_id}'>
                        Series 1: <input type='text' name='series1' value='{$row['series1']}'><br>
                        Series 2: <input type='text' name='series2' value='{$row['series2']}'><br>
                        Assignment 1: <input type='text' name='assignment1' value='{$row['assignment1']}'><br>
                        Assignment 2: <input type='text' name='assignment2' value='{$row['assignment2']}'><br>
                        Attendance : <input type='text' name='attendance' value='{$row['attendance']}'><br>
                        <input type='submit' value='Update Marks' name='update'>
                    ";
                }
            } else {
                echo "No data.";
            }

        }
    ?>
</form>
<?php 
    $ktu_id = $_POST['ktu_id'];
    $series1 = $_POST['series1'];
    $series2 = $_POST['series2'];
    $assignment1 = $_POST['assignment1'];
    $assignment2 = $_POST['assignment2'];
    $attendance = $_POST['attendance'];
    
    if ($_POST['add']) {
        // Add marks to the table
        $sql = "INSERT INTO marks VALUES ('$ktu_id', $series1, $series2, $assignment1, $assignment2, $attendance)";
        $result = mysqli_query($conn,$sql);

		if ($result) {
			echo "Marks added successfully";
		}
		else {
			echo "Cannot add marks";
		}
    } else if ($_POST['update']) {
        // Update marks
        $sql = "UPDATE marks SET series1 = $series1, series2 = $series2, assignment1 = $assignment1, assignment2 = $assignment2, attendance = $attendance WHERE ktu_id = '$ktu_id'";
        $result = mysqli_query($conn,$sql);
		if ($result) {
			echo "Marks updated successfully";
		}
		else {
			echo "Cannot update marks";
		}
    }
?>
