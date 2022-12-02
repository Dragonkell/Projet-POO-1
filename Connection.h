#pragma once
#include <String>


using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::Xml;
using namespace System;

// On cr�e un namespace specifique pour les composants, �a permet de regrouper les classes
// C'est purement cosm�tique mais permet d'avoir un code plus elegant

namespace BDD
{
	ref class Connection
	{
	private:
		// Contient les informations de connexion
		String^ connectionInformation;

		// Le nom de la requete SQL en cours
		String^ sqlRequest;

		// La connexion SQL
		SqlConnection^ sqlConnection;

		// La commande SQL
		SqlCommand^ sqlCommand;
		SqlDataAdapter^ sqlAdapter;

		// Les donnees renvoyees par les requetes
		DataSet^ dataSet;

		// Affecte la requete SQL
		void setSQL(String^ request);
	public:
		Connection(void);
		// Utiliser pour ajouter un element � la base en retournant l'id de l'element
		int actionRowsID(String^ request);

		// Utiliser pour modifier ou supprimer une element de la base
		void actionRows(String^ request);

		// Utiliser pour recuperer de la donnees de la base
		DataSet^ getRows(String^ request, String^ dataTableName);
	};
}