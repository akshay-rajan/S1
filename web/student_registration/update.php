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
                        Series 1: <input type='text' name='series1' value='{$row['series1']}'><br>
                        Series 2: <input type='text' name='series2' value='{$row['series2']}'><br>
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
    if ($_POST['add']) {
        // Add marks to the table
        
    } else if ($_POST['update']) {
        // Update marks

    }
?>