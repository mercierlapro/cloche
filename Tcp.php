
<?php
	class TcpWeb{

		private $adress;
		private $port;
		private $socket;

		public function __construct($adress,$port){
			$this->adress=$adress;
			$this->port=$port;
			echo "Création du socket";
			$this->socket= socket_create(AF_INET, SOCK_STREAM, SOL_TCP);
			if ($this->socket === false) {
				echo "socket_create() a echoué".socket_strerror(socket_last_error())."<br>";
			}else{
				echo "OK.<br>";
				}

		}
		private function connexion()
		{
			echo "Essai de connexion à ".$this->adress." sur le port ".$this->port."";
			$result=socket_connect($this->socket, $this->address, $this->port);//Ip du pc avec lequel on communique
			if($socket === false){
				echo "socket_connect() a échoué:(".$result.")".socket_strerror(socket_last_error($this->socket))."<br>";
				return false;
			}
			else{
				echo "OK<br>";
				return true;
			}
		}

		public function lecture(){

			if(connexion()==true){
				echo "Lire la réponse: \n\n";
				$out=socket_read($this->socket,200,PHP_BINARY_READ);
				echo $out;
				echo '<br>';
			}
			else{
				echo "problème de lecture";
			}
			
		}
		public function Fermeture(){

			echo "Fermeture du socket";
			socket_close($this->socket);
			echo "Ok <br>";

		}

	}
		
		
	

?>
</body>
</html>