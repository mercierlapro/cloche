<?php
include("CUser.php");
include("CBdd.php");
?>
<!DOCTYPE html>
<html>
<head>
	<title>test</title>
	<meta charset="utf-8">
</head>
<body>
	<form method="POST">
		login : <input type="text" name="login"><br>
		mdp : <input type="text" name="mdp"><br>
		<input type="submit" name="envoyer">
	</form>
</body>
</html>