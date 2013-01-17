<!DOCTYPE html>
<html>
<body>


<?php 

echo "TED2000 Menu";

// you define this variable here so that it exists for the call to exec
$output = null;

// Windows users: 'dir c:\\' or something similar
exec('ls', $output);
echo "<pre>" . var_export($output, TRUE) . "</pre>\\n";

echo "<button type='button' onclick='alert('Hello world!')'>Logout</button><br>"
echo "<button type='button' onclick='alert('Hello world!')'>Position ID</button><br>"
echo "<button type='button' onclick='alert('Hello world!')'>Program</button><br>"
echo "<button type='button' onclick='alert('Hello world!')'>Read</button><br>"
echo "<button type='button' onclick='alert('Hello world!')'>Maintenance</button><br>"

?>
 
</body>
</html>
