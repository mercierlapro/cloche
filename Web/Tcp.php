
<?php
	class TcpWeb{

		private $adress;
		private $port;
		private $socket;
		private $Etat;

		public function __construct($adress,$port,$trame)
		{
			//création du port

			$this->adress=$adress;
			$this->port=$port;
			echo "Création du socket";
			$this->socket= socket_create(AF_INET, SOCK_STREAM, 0);
			if ($this->socket === false) 
			{
				echo "socket_create() a echoué".socket_strerror(socket_last_error())."<br>";
			}
			else
			{
				echo "OK.<br>";
			}

			// appel des fonctions

			$this->connexion();
			
			$this->envoyer($trame);
		
			$this->fermeture();


		}
		//foncion de connexion a un serveur
		private function connexion()
		{
			echo "Essai de connexion à ".$this->adress." sur le port ".$this->port."";
			$this->Etat=socket_connect($this->socket, $this->adress, $this->port);//Ip du pc avec lequel on communique
			if($this->socket === false)
			{
				echo "socket_connect() a échoué:(".$result.")".socket_strerror(socket_last_error($this->socket))."<br>";
				return false;
			}
			else
			{
				echo "OK<br>";
				return true;
			}
		}

		//fonction de lecture au client
		private function lecture(){

			if($this->Etat==true)
			{
				echo "Lire la réponse: \n\n";
				$out=socket_read($this->socket,2048,PHP_NORMAL_READ);
				echo $out;
				echo '<br>';
			}
			else
			{
				echo "problème de lecture";
			}
			
		}

		//fermeture du socket
		private function Fermeture(){

			echo "Fermeture du socket";
			socket_close($this->socket);
			echo "Ok <br>";

		}

		//foncion d'envoie d'une trame
		private function envoyer($trame){


			if ($this->Etat==true) {
				
				$length= strlen($trame);
				socket_write($this->socket, $trame, $length);

			}
		}

	}
		
		
	

?>
</body>
</html>