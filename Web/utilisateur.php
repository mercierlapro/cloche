<?php


class utilisateur{

			private $_Name;
			private $_Pwrd;
			private $_Bdd;
			private $_connect = false;

//On définie les variables
	function __construct($name,$pswrd,$host,$dbname,$username,$mdp){

			$this->_Name=$name;
			$this->_Pwrd=$pswrd;
			$this->connexionBdd($host,$dbname,$username,$mdp);		
	}
//vérifie la connection	
	public function  isConnect()
	{
			return $this->_connect;
	}
//Permet de se connecter à la bdd
	private function connexionBdd($host,$dbname,$username,$mdp){
			try
			{
				$this->_Bdd= new PDO('mysql:host='.$host.';dbname='.$dbname.'',$username,$mdp);
			}
			catch(Exception $e)
			{
				echo $e->getMessage();
			}
	}
//Compare la BDD avec les informations rentrées dans le formulaire
	public function compare($table)
	{	
		$connect=$this->_Bdd->query("SELECT * FROM ".$table." WHERE `username` = '".$this->_Name."' AND `password` = '".$this->_Pwrd."'");

		//on vérifie si au moins 1 ligne à était éxécuté avec rowcount();
			if($connect->rowCount() > 0)
			{
				echo"Connexion reussie";
				$this->_connect = true;	
			}
			else
			{
				echo "erreur login/psw";
				$this->_connect = false;
			}
		
	}
//cette fonction permet de s'inscrire à la bdd
	public function inscription($table)
	{

			if($this->_Bdd->query("INSERT INTO ".$table."(`username`, `password`) VALUES ('".$this->_Name."','".$this->_Pwrd."')"))
			{
				echo "Inscription réussie";
			}
			else
			{
				echo"Pas reussie";
			}


	}

	
}
?>
	