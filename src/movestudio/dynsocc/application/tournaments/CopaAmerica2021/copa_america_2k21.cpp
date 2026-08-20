
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Chương trình
struct Player
{
	std::wstring name;
	int birth_year;

	std::wstring club;
	std::wstring club_country;

	std::wstring position_major; // GK, FW, DF, CM, DM, ST
	vector<std::wstring> positions;
};

struct Stadium
{
	std::wstring name;
	std::wstring full_name;
	std::wstring city;
	std::wstring country;
	std::wstring description;
	int capacity;
	int active_year;
};

struct Team
{
	std::wstring country_name;

	vector<Player> players;
	vector<int> shirtnumbers;
};

struct Tournament
{
	vector<Stadium> stadiums;
};

//================================================================================
//	EMBEDDED DATA
const wchar_t* wszSquads = LR"SQUAD0000(
Team: Argentina
	Head coach: Lionel Scaloni
	1; GK; Franco Armani;			1986; River Plate/Argentina
	2; DF; Lucas Martínez Quarta;	1996; Fiorentina/Italia
	3; DF; Nicolás Tagliafico; 		1992; Ajax/Netherlands
	4; DF; Gozalo Montiel;			1997; River Plate/Argentina
	5; MF; Leandro Paredes; 		1994; Paris Saint-Germain/France
	6; DF; Germán Pezzella; 		1991; Fiorentina/Italia
	7; MF; Rodrigo De Paul; 		1994; Udinese/Italia
	8; DF; Marcos Acuña; 			1991; Sevilla/Spain 
	9; FW; Sergio Agüero;			1988; Barcelona/Spain
	10; FW; Lionel Messi(Captain);	1987; Barcelona/Spain 
	11; FW; Ángel Di María; 		1988; Paris Saint-Germain/France
	12; GK; Augustín Marchesín;  	1988; Porto/Portugal
	13; DF; Cristian Romero; 		1998; Atalanta/Italia
	14; MF; Exequiel Palacios; 		1998; Bayer Leverkusen/Germany
	15; FW; Nicolás González; 		1998; VfB Stuttgart/Germany
	16; FW; Joaquín Correa; 		1994; Lazio/Italia
	17; MF; Nicolás Domínguez; 		1998; Bologna/Italia
	18; MF; Guido Rodríguez; 		1994; Real Betis/Spain
	19; DF; Nicolás Otamendi; 		1988; Benfica/Portugal
	20; MF; Giovani Lo Celso; 		1996; Tottenham Hotspur/England
	21; FW; Ángel Correa; 			1995; Atlético Madrid/Spain
	22; FW; Lautaro Martínez; 		1997; Internazionale/Italia
	23; GK; Emiliano Martínez; 		1992; Aston Villa/England
	24; FW; Alejandro Gómez; 		1988; Sevilla
	25; DF; Lisandro Martínez; 		1998; Ajax/Netherlands
	26; DF; Nahuel Molina; 			1998; Udinese/Italia 
	27; FW; Julián Álvarez;			2000; River Plate/Argentina 
	28; GK; Juan Musso; 			1994; Udinese/Italia
Team: Bolivia 
	Head Coach: César Farías  (National: Venezuela)
	1; GK; Carlos Lampe; 			1987; Always Ready/Bolivia
	2; DF; Jairo Quinteros; 		2001; Bolívar/Bolivia 
	3; DF; José Sagredo; 			1994; The Strongest/Bolivia 
	4; DF; Luis Haquin; 			1997; Melipilla/Chile
	5; DF; Adrián Jusino; 			1992; AEL/Greek
	6; MF; Leonel Justiniano		1992; Bolívar/Bolivia
	7; MF; Juan Carlos Arce; 		1985; Always Ready/Bolivia
	8; DF; Diego Bejarano; 			1991; Bolívar/Bolivia 
	9; FW; Marcelo Moreno (Captain);1987; Cruzeiro/Brazil
	10; FW; Henry Vaca; 			1998; Oriente Petrolero/Bolivia
	11; FW; Rodrigo Ramallo;		1990; Always Ready/Bolivia 
	12; FW; Rubén Cordano; 			1998; Bolívar/Bolivia
	13; FW; Diego Wayar; 			1993; The Strongest/Bolivia
	14; MF; Moisés Villarroel; 		1998; Jorge Wilstermann/Bolivia
	15; MF; Boris Céspedes; 		1995; Servette/Switzerland
	16; MF; Erwin Saavedra; 		1996; Bolívar/Bolivia 
	17; MF; Roberto Fernández; 		1999; Bolívar/Bolivia 
	18; FW; Gilbert Álvarez; 		1992; Jorge Wilstermann/Bolivia 
	19; DF; Enrique Flores; 		1994; Always Ready/Bolivia 
	20; MF; Ramiro Vaca; 			1999; The Strongest/Bolivia 
	21; MF; Erwin Sanchez; 			1992; Blooming/Bolivia 
	22; MF; Danny Bejarano; 		1994; Lamia/Greek 
	23; GK; Javier Rojas; 			1996; Bolívar/Bolivia
	24; FW; Jaume Cuélla; 			2001; SPAL/Italia 
	25; FW; Jeyson Chura;			2002; The Strongest/Bolivia 
	26; DF; Luis René Barboza; 		1993; Aurora/Bolivia 
	27; DF; Óscar Ribéra;			1992; Blooming/Bolivia  

Team: Uruguay 
	Head coach: Óscar Tabárez (National: Uruguay)
	1; GK; Fernando Muslera; 		1986; Galatasary/Turkey 
	2; DF; José Giménez; 			1995; Atlético Madrid/Spain 
	3; DF; Diego Godin (Captain);	1986; Cagliari/Italia 
	4; DF; Ronald Araújo; 			1999; Barcelona/Spain 
	5; MF; Matías Vecino; 			1991; Internazionale/Italia
	6; MF; Rodirigo Bentacur;		1997; Juventus/Italia 
	7; MF; Nicolás De La Cruz;  	1997; River Plate/Argentina 
	8; MF; Nahitan Nández;			1995; Cagliari/Italia 
	9; FW; Luis Suárez;				1987; Atlético Madrid/Spain
	10; MF; Giorgian De Arracaesta; 1994; Flamengo/Brazil
	11; DF; Camilo Cándido; 		1995; Nacional/Uruguay 
	12; GK; Martín Campaña; 		1989; Al-Batin/Saudi Arabia 
	13; DF; Giovanni González; 		1994; Peñarol/Uruguay 
	14; MF; Lucas Torreira; 		1996; Atlético Madrid/Spain 
	15; MF; Federico Valverde; 		1998; Real Madrid/Spain
	16; MF; Brian Rodríguez; 		2000; Amería/Spain 
	17; DF; Matías Viña;			1997; Palmeiras/Brazil
	18; FW; Maxi Gómez				1996; Valencia/Spain 
	19; DF; Sebástian Coates; 		1990; Sporting CP/Portugal
	20; FW; Jonathan Rodríguez;		1993; Cruz Azul/Mexico
	21; FW; Edinson Cavani; 		1987; Manchester United/England
	22; DF; Martín Cáceres;  		1987; Fiorentina/Italia 
	23; GK; Sergio Rochet; 			1993; Nacional/Uruguay
	24; MF; Fernando Gorriarán; 	1994; Santos Laguna/Mexico
	25; FW; Facundo Torres; 		2000; Peñarol/Uruguay
	26; FW; Brian Ocampo; 			1999; Nacional/Uruguay 

Team: Chile 
	Head Coach: Martín Lasarte
	1; GK; Claudio Bravo (Captain);	1983; Real Betis/Spain
	2; DF; Eugenio Mena; 			1988; Racing/Argentina 
	3; DF; Guillermo Maripán; 		1994; Monaco/France
	4; DF; Mauricio Isla; 			1988; Flamengo/Brazil
	5; DF; Enzo Roco;				1992; Fatih Karagümrük/Turkey
	6; DF; Francisco Sierralta;		1997; Watford/England 
	7; MF; César Pinares;  			1991; Grêmio/Brazil
	8; MF; Aturo Vidal; 			1987; Internazionale/Italia 
	9; FW; Jean Meneses; 			1993; León/Mexico
	10; FW; Alexis Sánchez; 		1988; Internazionale/Italia
	11; FW; Eduardo Vargas; 		1989; Atlético Mineiro/Brazil
	12; GK; Gabriel Arias; 			1987; Racing/Argentina 
	13; MF; Erick Pulga; 			1994; Fiorentina/Italia
	14; MF; Pablo Galdames;			1996; Velez Sarsfield/Argentina 
	15; DF; Daniel González; 		2002; Santiago Wanderers/Chile 
	16; FW; Felipe Mora; 			1993; Portland Timbers/USA 
	17; DF; Gary Medel; 			1987; Bologna/Italia
	18; DF; Sebástian Vegas; 		1996; Monterrey/Mexico 
	19; MF; Tómas Alarcón; 			1999; O'Higgins/Chile
	20; MF; Charles Aránguiz; 		1989; Bayer Leverkusen/Germany 
	21; FW; Carlos Palacios;		2000; Internacional/Brazil
	22; FW; Ben Brereton; 			1999; Blackburn Rovers/England 
	23; GK; Gabriel Castellón; 		1993; Huachipato/Chile
	24; FW; Luciano Arriagada; 		2002; Colo-Colo/Chile 
	25; MF; Marcelino Núñez;		2000; Universidad Católica/Chile
	26; FW; Clemente Montes; 		2001; Universidad Católica/Chile 	
	27; MF; Pablo Aránguiz; 		1997; Universidad De Chile/Chile
	28; MF; Claudio Baeza; 			1993; Toluca/Mexico

Team: Paraguay
	Head coach: Eduardo Berizzo (Argentina)
	1; GK; Atony Silva; 			1984; Puebla/Mexico
	2; DF; Robert Rojas; 			1996; River Plate/Argentina
	3; DF; Omar Alderete; 			1996; Hertha Berlin/Germany 
	4; DF; Fabián Balbuena;			1991; Westham United/England
	5; MF; Gastón Giménez; 			1991; Chicago Fire/Unites States
	6; DF; Júnior Alonso; 			1993; Atlestico Mineiro/Brazil
	7; FW; Carlos González; 		1993; UANL/Mexico
	8; MF; Richard Sánchez; 		1996; América/Mexico
	9; 
	10; 

)SQUAD0000";

//================================================================================

int initStadium(Tournament& t)
{
	t.stadiums.clear();

	Stadium stdu_estadio;
	Stadium stdu_pantanal;
	Stadium stdu_mane_garrincha;
	Stadium stdu_olympic;
	Stadium stdu_maracana;

	stdu_estadio.name = L"Estádio Olímpico Pedro Ludovico";
	stdu_estadio.full_name = L"Estádio Olímpico Pedro Ludovico Teixeira";
	stdu_estadio.capacity = 13500;
	stdu_estadio.city = L"Goiânia, Goiás, Brazil";
	stdu_estadio.country = L"Brazil";
	stdu_estadio.description = L"";
	stdu_estadio.active_year = 1941;

	stdu_pantanal.name = L"Arena Pantanal";
	stdu_pantanal.full_name = L"Arena Pantanal";
	stdu_pantanal.capacity = 44000;
	stdu_pantanal.city = L"Cuiabá, Mato Grosso, Brazil";
	stdu_pantanal.country = L"Brazil";
	stdu_pantanal.description = L"";
	stdu_pantanal.active_year = 2014;

	stdu_mane_garrincha.name = L"Estádio Nacional Mané Garrincha";
	stdu_mane_garrincha.full_name = L"Estádio Nacional Mané Garrincha";
	stdu_mane_garrincha.capacity = 72788;
	stdu_mane_garrincha.city = L"Brasília, Distrito Federal, Brazil";
	stdu_mane_garrincha.country = L"Brazil";
	stdu_mane_garrincha.description = L"Field size: 105m x 68m";
	stdu_mane_garrincha.active_year = 1973;

	stdu_olympic.name = L"Estádio Olímpico Nilton Santos";
	stdu_olympic.full_name = L"Estádio Olímpico Nilton Santos";
	stdu_olympic.capacity = 46931;
	stdu_olympic.city = L"Rio de Janeiro";
	stdu_olympic.country = L"Brazil";
	stdu_olympic.description = L"";
	stdu_olympic.active_year = 2007;

	stdu_maracana.name = L"Maracanã";
	stdu_maracana.full_name = L"Maracanã";
	stdu_maracana.capacity = 78838;
	stdu_maracana.city = L"Rio de Janeiro";
	stdu_maracana.country = L"Brazil";
	stdu_maracana.description = L"";
	stdu_maracana.active_year = 1950;


	t.stadiums.push_back(stdu_estadio);
	t.stadiums.push_back(stdu_pantanal);
	t.stadiums.push_back(stdu_mane_garrincha);
	t.stadiums.push_back(stdu_olympic);
	t.stadiums.push_back(stdu_maracana);
	return 0;
}

int initialize(Tournament& t)
{
	initStadium(t);
	return 0;
}

int fuzzeReading()
{
	// Read input with approximately format (Not 100% accuracy)
	// Approximately 
	return 0;
}

int main()
{
	Tournament t;
	initialize(t);

	std::cin;
	
	std::wcout << t.stadiums[0].name << std::endl;
	return 0;
};