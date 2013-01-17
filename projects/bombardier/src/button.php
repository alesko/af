<!DOCTYPE html>
<html>
<body>


<?php 

// you define this variable here so that it exists for the call to exec
$output = null;

// Windows users: 'dir c:\\' or something similar
exec('ls', $output);
echo "<pre>" . var_export($output, TRUE) . "</pre>\\n";

echo "PHP script with buttons";
?>

<button type="button" onclick="alert('Hello world!')">Click Me!</button><br>
<button type="button" onclick="alert('Hello world!')">Click Me!</button><br>
<button type="button" onclick="alert('Hello world!')">Click Me!</button><br>
<button type="button" onclick="alert('Hello world!')">Click Me!</button><br>

 
</body>
</html>
