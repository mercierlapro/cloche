<?php session_start(); ?>
<?php include("utilisateur.php"); include("Tcp.php"); ?>

<!DOCTYPE html>
<html>

<head>
	<meta charset="utf-8">
	<link rel="stylesheet" href="style.css" type="text/css">
	<title>Login</title>
</head>
<body>
						
	<?php 

		//on vérifie que le formulaire est rempli et qu'on appuie bien sur le bouton
		if (isset($_POST['button']) && !empty($_POST['username']) && !empty($_POST['password']))
		{

			$Utilisateur = new utilisateur($_POST['username'],$_POST['password'],'localhost','cloche','root','');
			$Utilisateur->compare('register');

			if($Utilisateur->isConnect())
			{
				echo"Connexion réussi!";
				$_SESSION["username"]=$_POST['username'];
				$_SESSION["password"]=$_POST['password'];
			}
			else
			{
				echo "Erreur: Login ou password incorrect!";
			}
		}

		//instance de l'objet de la classe utilisateur pour stocker dans la Session
		if(isset($_SESSION["username"]))
		{

			$Utilisateur = new utilisateur($_SESSION['username'],$_SESSION['password'],'localhost','cloche','root','','register');
			?>	
				<center>
					<!--formulaire pour choisir une cloche-->
				<h3>Sonner une cloche!</h3>
				<p>Bonjour</p>
					<div id="container2">
						<div id="form1">
						<form action="index.php" method="post" id="form1"> 
							<input type="submit" id="btncloche" name="btncloche1" value="Petite Cloche"><br><br>	
							<input type="submit" id="btncloche" name="btncloche2" value="Moyenne Cloche"><br><br>
							<input type="submit" id="btncloche" name="btncloche3" value="Intermediaire Cloche"><br><br>
							<input type="submit" id="btncloche" name="btncloche4" value="Grande Cloche"><br>
						</form>
						</div>
					</div>
						<form action="index.php" method="post">	
							<input type="submit" id="button" name="deconnexion" value="DECONNEXION">
						</form>
				</center>
			<?php
		}
		else
		{	
		//formulaire de connexion
			?>
				<div id="container">
					<h3>CONNEXION</h3>
						<form action="index.php" method="post">		
							<label>LOGIN<br>
							<input type="text" id="box" name="username"></label><br>
							<label>PASSWORD<br>
							<input type="password" id="box" name="password"></label>
							<input type="submit" id="button" name="button" value="CONNEXION"><br>
							<a href="index_inscription.php"> Inscription </a>
						</form>
				</div>

			<?php
		}
			//destruction de la variable SESSION
		if (isset($_POST['deconnexion']))
		{
				session_unset();
				session_destroy();
		}

			//on regarde quel bouton est activé		

		if (isset($_POST['btncloche1'])) {
			$Tcp= new TcpWeb('192.168.64.100','65535',"Cloche1\n");

		}
		if (isset($_POST['btncloche2'])) {
			$Tcp= new TcpWeb('192.168.64.100','65535',"Cloche2\n");

		}
		if (isset($_POST['btncloche3'])) {
			$Tcp= new TcpWeb('192.168.64.100','65535',"Cloche3\n");

		}
		if (isset($_POST['btncloche4'])) {
			$Tcp= new TcpWeb('192.168.64.100','65535',"Cloche4\n");

		}
	?>


</body>
</html>