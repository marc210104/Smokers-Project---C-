//Marc Ortiz Segura

#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

// Estructuras (tuplas)
struct FumadorNacionalEuropeo {
    string consumo;
    string grupo_edad;
    string encuesta;
    string sexo;
    int total;
    int unnamed;
};

struct FumadorSalud {
    string tipo;
    int anyo;
    string diagnostico;
    string condicion;
    float porcentaje;
};

/// Prototipos

void ConsultaGeneral(const vector<FumadorSalud>& datos, const string& diagn_us );
void Autoevaluacion_general(const vector<FumadorSalud>& FS, const vector<FumadorNacionalEuropeo>& FNE);
void Autoevaluacion_psicologica(const vector<FumadorSalud>& FS);
void compararPorcentaje(const vector<FumadorSalud>& datos, const string& tipoFumador);
void enfermedadMasComun(const vector<FumadorSalud>& datos, const string& tipoFumador);
void TendenciaEnfermedades(const vector<FumadorSalud>& datos, const string& enfermedad);
void GeneroQueMasFumaPorGrupoDeEdadEuropa(const vector<FumadorNacionalEuropeo>& datos,  string GrupoEdad);


//MAIN
int main(){
    ifstream fin1("EnquestaNacionalEuropea.txt");
    ifstream fin2("SaludMundial.txt");

    vector<FumadorNacionalEuropeo> FNE;
    vector<FumadorSalud> FS;
    FumadorNacionalEuropeo fne;
    FumadorSalud fs;

    while(fin1 >> fne.consumo >> fne.grupo_edad >> fne.encuesta >> fne.sexo >> fne.total >> fne.unnamed) FNE.push_back(fne);
    while(fin2 >> fs.tipo >> fs.anyo >> fs.diagnostico >> fs.condicion >> fs.porcentaje) FS.push_back(fs);

    int opcion = 0;

    while (opcion != 8) {
        cout << "\tMenu Principal:" << endl;
        cout << "\t" << endl;
        cout << "\t|=======================================|" << endl;
        cout << "\t| 1. Consulta general" << endl;
        cout << "\t| 2. Autoevaluacion general" << endl;
        cout << "\t| 3. Autoevaluacion psicologica" << endl;
        cout << "\t| 4. Comparar porcentajes por anyo y fumador" << endl;
        cout << "\t| 5. Enfermedad mas comun por tipo" << endl;
        cout << "\t| 6. Tendencia en enfermedades" << endl;
        cout << "\t| 7. Genero que mas fuma por grupo de edad" << endl;
        cout << "\t| 8. Salir" << endl;
        cout << "\t|=======================================|" << endl;
        system("pause");
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            string diagn_us;
            cout << "Ingrese el tipo de diagnostico a consultar (autoevaluado/Enfermedad/Psicologico): ";
            cin >> diagn_us;
            ConsultaGeneral(FS, diagn_us);
        } else if (opcion == 2) {
            Autoevaluacion_general(FS, FNE);
        } else if (opcion == 3) {
            Autoevaluacion_psicologica(FS);
        } else if (opcion == 4) {
            string tipoFumador;
            cout << "Ingrese el tipo de fumador (Ej.: Fumador_diario): ";
            cin >> tipoFumador;
            compararPorcentaje(FS, tipoFumador);
        } else if (opcion == 5) {
            string tipoFumador;
            cout << "Ingrese el tipo de fumador (Ej.: Fumador_diario): ";
            cin >> tipoFumador;
            enfermedadMasComun(FS, tipoFumador);
        } else if (opcion == 6) {
            string enfermedad;
            cout << "Desea empezar la consulta sobre la tendencia de enfermedades? (SI/NO): ";
            string respuesta;
            cin >> respuesta;
            while (respuesta == "SI") {
                cout << "Que enfermedad desea consultar (Ej.: Diabetes, Heart_diseases, Asthma, etc.)?" << endl;
                cin >> enfermedad;

                TendenciaEnfermedades(FS, enfermedad);
                cout << "Desea consultar otra enfermedad? (SI/NO): ";
                cin >> respuesta;
            }
        } else if (opcion == 7) {
            string grupoEdad;
            cout << "Ingrese el grupo de edad a consultar (Ej.: De_15_a_24_anyos): ";
            cin >> grupoEdad;
            GeneroQueMasFumaPorGrupoDeEdadEuropa(FNE, grupoEdad);
        } else if (opcion == 8) {
            cout << "Gracias por usar el programa." << endl;
        } else {
            cout << "Opcion no valida." << endl;
        }
    }

    return 0;
}


//SUBPROGRAMAS

void ConsultaGeneral(const vector<FumadorSalud>& datos, const string& diagn_us ){
    string cond_us;
    int anyo_us;
    string respuesta;
            if(diagn_us=="autoevaluado"){
                cout<<"Que condición desea consultar(Excellent/Very_good/Good/Fair/Poor)?"<<endl;
                cin>>cond_us;
                cout<<"Para que anyo(2007/2010/2013/2016/2019)?"<<endl;
                cin>>anyo_us;
            }
            else if(diagn_us=="Enfermedad"){
                cout<<"Que enfermedad desea consultar?"<<endl;
                cin>>cond_us;
                cout<<"Para que anyo(2007/2010/2013/2016/2019)?"<<endl;
                cin>>anyo_us;
            }
            else if(diagn_us=="Psicologico"){
                cout<<"Que estado mental desea consultar(Low/Moderate/High/Very_high?"<<endl;
                cin>>cond_us;
                cout<<"Para que anyo(2007/2010/2013/2016/2019)?"<<endl;
                cin>>anyo_us;
            }
            else {
                cout<<"El diagnostico introducido es incorrecto"<<endl;
                respuesta="NO";
            }
    
    for(int i=0;i<datos.size();i++){
        if(diagn_us==datos[i].diagnostico && datos[i].condicion==cond_us && datos[i].anyo==anyo_us){
            cout << "Anyo: " << datos[i].anyo << ", Diagnostico: " <<  datos[i].diagnostico << ", Condicion: " << datos[i].condicion << ", Porcentaje: " << datos[i].porcentaje << "%, de los cuales, se clasifican en:  " << datos[i].tipo << endl;
        }
    }
}
void Autoevaluacion_general(const vector<FumadorSalud>& FS, const vector<FumadorNacionalEuropeo>& FNE) {
    string tipo_usuario, condicion_usuario, diagnostico_usuario;
    string respuesta;
    int anyo_usuario;

    cout << "Deseas empezar la consulta? (SI/NO)" << endl;
    cin >> respuesta;

    while (respuesta == "SI") {
        cout << "Que tipo de fumador eres? (Fumador_diario, Fumador_ocasional, Exfumador, Nunca_ha_fumado, Todos): ";
        cin >> tipo_usuario;

        cout << "Como te consideras que estas? (Ej.: Excellent, Good, Poor, etc.): ";
        cin >> condicion_usuario;

        cout << "El diagnostico ha sido autoevaluado o reportado por un medico? (Ej.: autoevaluado, enfermedad, psicologico): ";
        cin >> diagnostico_usuario;

        cout << "Para que anyo deseas consultar? (2007/2010/2013/2016/2019): ";
        cin >> anyo_usuario;

        bool encontrado = false;
        for (int i = 0; i < FS.size(); i++) {
            if ((tipo_usuario == "Todos" || FS[i].tipo == tipo_usuario) &&
                FS[i].condicion == condicion_usuario &&
                FS[i].diagnostico == diagnostico_usuario &&
                FS[i].anyo == anyo_usuario) {
                cout << "Anyo: " << FS[i].anyo << ", Diagnostico: " << FS[i].diagnostico
                     << ", Condicion: " << FS[i].condicion << ", Porcentaje: " << FS[i].porcentaje << "%" << endl;
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No se encontraron datos para tu situacion especifica." << endl;
        }

        cout << "Deseas ver la estadistica europea o mundial? (europea/mundial): ";
        string opcion;
        cin >> opcion;

        if (opcion == "europea") {
            cout << "Selecciona un grupo de edad (Ej.: Total, De_15_a_24_anyos): ";
            string grupo_edad_usuario;
            cin >> grupo_edad_usuario;

            cout << "Selecciona un sexo (Ej.: Hombres, Mujeres): ";
            string sexo_usuario;
            cin >> sexo_usuario;

            for (int i = 0; i < FNE.size(); i++) {
                if ((grupo_edad_usuario == "Todos" || FNE[i].grupo_edad == grupo_edad_usuario) &&
                    (sexo_usuario == "Todos" || FNE[i].sexo == sexo_usuario)) {
                    cout << "Consumo: " << FNE[i].consumo << ", Grupo de edad: " << FNE[i].grupo_edad
                         << ", Sexo: " << FNE[i].sexo << ", Porcentaje: " << FNE[i].total << "%" << endl;
                }
            }
        } else if (opcion == "mundial") {
            cout << "Selecciona una condicion global para consultar (Ej.: Excellent, Diabetes): ";
            string condicion_global_usuario;
            cin >> condicion_global_usuario;

            for (int i = 0; i < FS.size(); i++) {
                if (FS[i].condicion == condicion_global_usuario) {
                    cout << "Anyo: " << FS[i].anyo << ", Diagnostico: " << FS[i].diagnostico << ", Porcentaje: " << FS[i].porcentaje << "%" << endl;
                }
            }
        } else {
            cout << "Opcion no valida." << endl;
        }

        cout << "Deseas realizar otra consulta? (SI/NO): ";
        cin >> respuesta;
    }
}
void Autoevaluacion_psicologica(const vector<FumadorSalud>& FS) {
    string tipo_usuario, condicion_usuario;

    cout << "Que tipo de fumador eres? (Fumador_diario, Fumador_ocasional, Exfumador, Nunca_ha_fumado, Todos): ";
    cin >> tipo_usuario;

    cout << "Como describirias tu estado psicologico? (Low, Moderate, High, Very_high, High/Very_high): ";
    cin >> condicion_usuario;

    bool encontrado = false;
    for (int i = 0; i < FS.size(); i++) {
        if ((tipo_usuario == "Todos" || FS[i].tipo == tipo_usuario) && 
            FS[i].diagnostico == "Psicologico" && 
            (FS[i].condicion == condicion_usuario || 
             (condicion_usuario == "High/Very_high" && FS[i].condicion == "High/Very_high"))) {
            cout << "En el anyo " << FS[i].anyo << ", el " << FS[i].porcentaje
                 << "% de las personas reportaron tu mismo estado psicologico." << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron datos para tu situacion especifica." << endl;
    }

    cout << "Deseas filtrar los datos por anyo? (si/no): " << endl;
    string opcion;
    cin >> opcion;

    if (opcion == "si") {
        cout << "Selecciona un anyo (2007/2010/2013/2016/2019): " << endl;
        int anyo_filtro;
        cin >> anyo_filtro;

        for (int i = 0; i < FS.size(); i++) {
            if (FS[i].anyo == anyo_filtro && 
                (tipo_usuario == "Todos" || FS[i].tipo == tipo_usuario) && 
                FS[i].diagnostico == "Psicologico" && 
                (FS[i].condicion == condicion_usuario || 
                 (condicion_usuario == "High/Very_high" && FS[i].condicion == "High/Very_high"))) {
                cout << "Tipo: " << FS[i].tipo << ", Condicion: " << FS[i].condicion
                     << ", Porcentaje: " << FS[i].porcentaje << " % " << endl;
            }
        }
    } else {
        cout << "No se aplico ningun filtro adicional." << endl;
    }
}
void compararPorcentaje(const vector<FumadorSalud>& datos, const string& tipoFumador) {
    string enfermedadUsuario;
    cout << "Introduzca la enfermedad para ver el cambio del porcentaje de " << tipoFumador << " que la padecen: ";
    cin >> enfermedadUsuario;

    vector<int> anyos;
    vector<float> porcentajes;

    for (int i = 0; i < datos.size(); i++) {
        if (datos[i].tipo == tipoFumador && datos[i].condicion == enfermedadUsuario) {
            anyos.push_back(datos[i].anyo);
            porcentajes.push_back(datos[i].porcentaje);
            cout << "Anyo: " << datos[i].anyo << ", Diagnostico: " << datos[i].diagnostico
                 << ", Condicion: " << datos[i].condicion << ", Porcentaje: " << datos[i].porcentaje << "%" << endl;
        }
    }

    if (anyos.empty()) {
        cout << "No se encontraron datos para " << enfermedadUsuario << " en el tipo de fumador " << tipoFumador << "." << endl;
        return;
    }

    // Ordenar los datos por año y asociar índices para el primer y último año
    int primerAnyoIndex = 0, ultimoAnyoIndex = anyos.size() - 1;

    if (porcentajes[primerAnyoIndex] > porcentajes[ultimoAnyoIndex]) {
        cout << "La tendencia de " << enfermedadUsuario << " es negativa, por lo que hay cada vez menos afectados." << endl;
    } else if (porcentajes[primerAnyoIndex] < porcentajes[ultimoAnyoIndex]) {
        cout << "La tendencia de " << enfermedadUsuario << " es positiva, por lo que hay cada vez mas afectados." << endl;
    } else {
        cout << "Las cifras de afectados por " << enfermedadUsuario << " no han cambiado con el tiempo." << endl;
    }
}
void enfermedadMasComun(const vector<FumadorSalud>& datos, const string& tipoFumador) {
	
    string enfermedadMax;
    int anyoMax;
    float porcentajeMax = -1;

    for (int i = 0; i < datos.size(); i++) {
        if (datos[i].tipo == tipoFumador && datos[i].porcentaje > porcentajeMax && datos[i].porcentaje != -1 && datos[i].diagnostico == "enfermedad") {
            porcentajeMax = datos[i].porcentaje;
            enfermedadMax = datos[i].condicion;
            anyoMax = datos[i].anyo;
        }
    }

    if (porcentajeMax == -1) {
        cout << "No se encontraron datos validos para " << tipoFumador << " en la categoria Enfermedad." << endl;
    } else {
        cout << "Enfermedad mas comun para " << tipoFumador << ": " << enfermedadMax
             << " con " << porcentajeMax << "% de prevalencia en el anyo " << anyoMax << endl;
    }
}
void TendenciaEnfermedades(const vector<FumadorSalud>& datos, const string& enfermedad) {
    vector<int> anyos;
    vector<float> porcentajes;

    for (int i = 0; i < datos.size(); i++) {
        if (datos[i].condicion == enfermedad) {
            anyos.push_back(datos[i].anyo);
            porcentajes.push_back(datos[i].porcentaje);
        }
    }

    if (anyos.empty()) {
        cout << "No se encontraron datos para la enfermedad especificada: " << enfermedad << endl;
        return;
    }

    for (int i = 0; i < anyos.size() - 1; i++) {
        for (int j = 0; j < anyos.size() - i - 1; j++) {
            if (anyos[j] > anyos[j + 1]) {
                int tempAnyo = anyos[j];
                anyos[j] = anyos[j + 1];
                anyos[j + 1] = tempAnyo;

                float tempPorcentaje = porcentajes[j];
                porcentajes[j] = porcentajes[j + 1];
                porcentajes[j + 1] = tempPorcentaje;
            }
        }
    }

    cout << "Tendencia de la enfermedad: " << enfermedad << endl;
    for (int i = 0; i < anyos.size(); i++) {
        cout << "Anyo: " << anyos[i] << ", Porcentaje: " << porcentajes[i] << "%" << endl;
    }

    if (porcentajes.size() > 1) {
        if (porcentajes[porcentajes.size() - 1] > porcentajes[0]) {
            cout << "El porcentaje de la enfermedad ha aumentado con el paso del tiempo." << endl;
        } else if (porcentajes[porcentajes.size() - 1] < porcentajes[0]) {
            cout << "El porcentaje de la enfermedad ha disminuido con el paso del tiempo." << endl;
        } else {
            cout << "El porcentaje de la enfermedad se ha mantenido constante con el paso del tiempo." << endl;
        }
    } else {
        cout << "Solo hay un dato disponible para la enfermedad especificada." << endl;
    }
}
void GeneroQueMasFumaPorGrupoDeEdadEuropa(const vector<FumadorNacionalEuropeo>& datos,  string GrupoEdad){
    string respuesta;
    bool trobat=false;
    int porcentajeH=0,porcentajeM=0;
    cout<<"Desea empezar la busqueda?(SI/NO)"<<endl;
    cin>>respuesta;
    while(respuesta=="SI"){
        for(int i=0; i<datos.size() && !trobat; i++){
            if(datos[i].grupo_edad==GrupoEdad && datos[i].encuesta=="E._Europea_de_Salud_2020"){
                if(datos[i].sexo=="Hombres") {
                        porcentajeH=datos[i].total;
                        porcentajeM=datos[i+1].total;
                        trobat=true;
                }
            }
        }
        if(porcentajeH>porcentajeM) cout<<"Para ese grupo de edad hay mas hombres que fumen"<<endl;
        else if(porcentajeH<porcentajeM) cout<<"Para ese grupo de edad hay mas mujeres que fumen"<<endl;
        else cout<<"Para ese grupo de edad la cantidad de hombres y de mujeres que fuman es la misma"<<endl;

        cout<<"Desea continuar buscando?"<<endl;
        cin>>respuesta;
        cout << " Introduzca otro grupo de edad" << endl;
        cin>>GrupoEdad;
    }

}

