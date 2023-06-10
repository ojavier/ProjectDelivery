#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;


//Las Clases Fecha y Hora no poseen relevancia para el propósito del programa,
//mas bien son clases auxiliares para poder tener un formato
class Fecha {
private:
    int dia;
    int mes;
    int ano;

public:
    // Constructor
    Fecha(int d, int m, int a) : dia(d), mes(m), ano(a) {}

    // Métodos de acceso
    int getDia() const { return dia; }
    int getMes() const { return mes; }
    int getAno() const { return ano; }

    // Sobrecarga del operador de inserción <<
    friend std::ostream& operator<<(std::ostream& os, const Fecha& fecha) {
        os << fecha.dia << "/" << fecha.mes << "/" << fecha.ano;
        return os;
    }
};

class Hora {
private:
    int horas;
    int minutos;

public:
    // Constructor
    Hora(int h, int m) : horas(h), minutos(m) {}

    // Métodos de acceso
    int getHoras() const { return horas; }
    int getMinutos() const { return minutos; }

    // Sobrecarga del operador de inserción <<
    friend std::ostream& operator<<(std::ostream& os, const Hora& hora) {
        os << hora.horas << ":" << hora.minutos;
        return os;
    }
};

// Clase Pago para simular el pago de un boleto
class Pago {
private:
    int idPago;
    int idUsuario;
    int idBoleto;
    Fecha fechaPago;
    float monto;

public:
    // Constructor
    Pago(int id, int idUsuarioPago, int idBoletoPago, const Fecha& fecha, float montoPago)
        : idPago(id), idUsuario(idUsuarioPago), idBoleto(idBoletoPago), fechaPago(fecha), monto(montoPago) {}

    // Getters
    int getIdPago() const {
        return idPago;
    }

    int getIdUsuario() const {
        return idUsuario;
    }

    int getIdBoleto() const {
        return idBoleto;
    }

    Fecha getFechaPago() const {
        return fechaPago;
    }

    float getMonto() const {
        return monto;
    }

    // Setters
    void setIdPago(int id) {
        idPago = id;
    }

    void setIdUsuario(int idUsuarioPago) {
        idUsuario = idUsuarioPago;
    }

    void setIdBoleto(int idBoletoPago) {
        idBoleto = idBoletoPago;
    }

    void setFechaPago(const Fecha& nuevaFecha) {
        fechaPago = nuevaFecha;
    }

    void setMonto(float nuevoMonto) {
        monto = nuevoMonto;
    }

    // Otros métodos
    void realizarPago() {
        cout << "Realizando pago con ID: " << idPago << endl;
        // Lógica para realizar el pago
    }

    void cancelarPago() {
        cout << "Cancelando pago con ID: " << idPago << endl;
        // Lógica para cancelar el pago
    }
};

class Usuario; // Declaración anticipada de la clase Usuario

// Clase Boleto para representar un boleto que posea el usuario
class Boleto {
private:
    int idBoleto;
    string origen;
    string destino;
    Fecha fecha;
    Hora hora;
    Usuario* usuario;
    vector<Pago*> pagos;
    float costo;      // Atributo para el costo del boleto
    int asiento;      // Atributo para el número de asiento asignado

public:
    // Constructor
    Boleto(int id, const string& origenBoleto, const string& destinoBoleto, const Fecha& fechaViaje, const Hora& horaViaje, float costoBoleto)
        : idBoleto(id), origen(origenBoleto), destino(destinoBoleto), fecha(fechaViaje), hora(horaViaje), usuario(nullptr), costo(costoBoleto), asiento(0) {}

    // Getters
    int getIdBoleto() const {
        return idBoleto;
    }

    string getOrigen() const {
        return origen;
    }

    string getDestino() const {
        return destino;
    }

    Fecha getFecha() const {
        return fecha;
    }

    Hora getHora() const {
        return hora;
    }

    Usuario* getUsuario() const {
        return usuario;
    }

    float getCosto() const {
        return costo;
    }

    int getAsiento() const {
        return asiento;
    }

    // Setter
    void setUsuario(Usuario* usuario) {
        this->usuario = usuario;
    }

    // Otros métodos
    void realizarPago() {
        cout << "Realizando pago del boleto ID: " << idBoleto << endl;
        // Lógica de pago
    }

    void cancelarReserva() {
        cout << "Cancelando reserva del boleto ID: " << idBoleto << endl;
        // Lógica de cancelación de reserva
    }

    void agregarPago(Pago* pago) {
        cout << "Agregando pago al boleto ID: " << idBoleto << endl;
        pagos.push_back(pago);
    }

    // Setters
    void setIdBoleto(int id) {
        idBoleto = id;
    }

    void setOrigen(const string& nuevoOrigen) {
        origen = nuevoOrigen;
    }

    void setDestino(const string& nuevoDestino) {
        destino = nuevoDestino;
    }

    void setFecha(const Fecha& nuevaFecha) {
        fecha = nuevaFecha;
    }

    void setHora(const Hora& nuevaHora) {
        hora = nuevaHora;
    }

    void setCosto(float nuevoCosto) {
        costo = nuevoCosto;
    }

    void setAsiento(int nuevoAsiento) {
        asiento = nuevoAsiento;
    }
};

// Clase virtual Persona para representar una persona y que ciertos atributos puedan ser aplicados en otras clases
class Persona {
protected:
    string nombre;
    int edad;
    int id;

public:
    Persona(const string& nombre, int edad, int id)
        : nombre(nombre), edad(edad), id(id) {}

    void mostrarInformacion() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
        cout << "ID: " << id << endl;
    }

    string getNombre() const {
        return nombre;
    }

    void setNombre(const string& nuevoNombre) {
        nombre = nuevoNombre;
    }

    int getEdad() const {
        return edad;
    }

    void setEdad(int nuevaEdad) {
        edad = nuevaEdad;
    }

    int getID() const {
        return id;
    }

    void setID(int nuevoID) {
        id = nuevoID;
    }
};

// Clase Usuario para representar a un usuario del sistema
class Usuario : public Persona {
private:
    string idUsuario;
    string correoElectronico;
    string contrasena;
    vector<Boleto*> boletos;
    vector<Pago*> pagos;

public:
    Usuario(int id, const string& nombre, int edad, const string& correo, const string& contrasena)
        : Persona(nombre, edad, id), correoElectronico(correo), contrasena(contrasena) {}

    void mostrarInformacion() const {
        Persona::mostrarInformacion();
        cout << "Correo: " << correoElectronico << endl;
        cout << "Contraseña: " << contrasena << endl;
    }

    void iniciarSesion() {
        cout << "Iniciando sesión como " << nombre << endl;
        // Lógica de inicio de sesión
    }

    void realizarReserva(Boleto* boleto) {
        cout << "Realizando reserva del boleto ID: " << boleto->getIdBoleto() << " para el usuario " << nombre << endl;
        // Lógica para realizar la reserva
    }

    void cancelarReserva(Boleto* boleto) {
        cout << "Cancelando reserva del boleto ID: " << boleto->getIdBoleto() << " para el usuario " << nombre << endl;
        // Lógica para cancelar la reserva
    }

    void agregarBoleto(Boleto* boleto) {
        cout << "Agregando boleto ID: " << boleto->getIdBoleto() << " al usuario " << nombre << endl;
        boletos.push_back(boleto);
    }

    void agregarPago(Pago* pago) {
        cout << "Agregando pago al usuario " << nombre << endl;
        pagos.push_back(pago);
    }

    string getCorreoElectronico() const {
        return correoElectronico;
    }

    void setCorreoElectronico(const string& nuevoCorreo) {
        correoElectronico = nuevoCorreo;
    }

    string getContraseña() const {
        return contrasena;
    }

    void setContrasena(const string& nuevaContrasena) {
        contrasena = nuevaContrasena;
    }
};

// Clase Conductor para representar a un conductor del sistema
class Conductor : public Persona {
private:
    int idConductor;

public:
    Conductor(const std::string& nombre, int edad, int id, int idConductor)
        : Persona(nombre, edad, id), idConductor(idConductor) {}

    void mostrarInformacion() const {
        cout << "--- Información del Conductor ---" << endl;
        Persona::mostrarInformacion();
        cout << "ID Conductor: " << idConductor << endl;
    }

    int getIDConductor() const {
        return idConductor;
    }

    void setIDConductor(int nuevoIDConductor) {
        idConductor = nuevoIDConductor;
    }
};

// Declaración anticipada de la clase Autobus
class Autobus;

// Clase Ruta para simular las distintas rutas posibles
class Ruta {
private:
    int idRuta;
    string origen;
    string destino;
    Autobus* autobus;  // Relación de agregación con la clase Autobus

public:
    // Constructor
    Ruta(int id, const string& origenRuta, const string& destinoRuta)
        : idRuta(id), origen(origenRuta), destino(destinoRuta), autobus(nullptr) {}

    // Getters
    int getIdRuta() const {
        return idRuta;
    }

    string getOrigen() const {
        return origen;
    }

    string getDestino() const {
        return destino;
    }

    Autobus* getAutobus() const {
        return autobus;
    }

    // Otros métodos
    void agregarRuta() {
        std::cout << "Ruta agregada con ID: " << idRuta << std::endl;
        // Lógica para agregar la ruta
    }

    void eliminarRuta() {
        std::cout << "Ruta eliminada con ID: " << idRuta << std::endl;
        // Lógica para eliminar la ruta
    }

    // Setters
    void setIdRuta(int id) {
        idRuta = id;
    }

    void setOrigen(const string& nuevoOrigen) {
        origen = nuevoOrigen;
    }

    void setDestino(const string& nuevoDestino) {
        destino = nuevoDestino;
    }

    void setAutobus(Autobus* nuevoAutobus) {
        autobus = nuevoAutobus;
    }
};

// Clase Autobus para representar a un autobus
class Autobus : public Conductor {
private:
    int idAutobus;
    string modelo;
    int capacidadMaxima;
    Ruta* ruta;  // Relación de agregación con la clase Ruta
    vector<Boleto*> boletos;  // Relación de agregación con la clase Boleto

public:
    // Constructor
    Autobus(int id, const string& modeloAutobus, int capacidad, const string& conductorAutobus, int idConductor)
        : Conductor(conductorAutobus, 0, id, idConductor), idAutobus(id), modelo(modeloAutobus), capacidadMaxima(capacidad), ruta(nullptr) {}

    // Getters
    int getIdAutobus() const {
        return idAutobus;
    }

    string getModelo() const {
        return modelo;
    }

    int getCapacidadMaxima() const {
        return capacidadMaxima;
    }

    Ruta* getRuta() const {
        return ruta;
    }

    const vector<Boleto*>& getBoletos() const {
        return boletos;
    }

    // Otros métodos
    bool verificarDisponibilidad() {
        // Lógica para verificar la disponibilidad del autobús
    }

    void reservarAsiento() {
        // Lógica para reservar un asiento en el autobús
    }

    // Método para agregar un boleto al autobús
    void agregarBoleto(Boleto* boleto) {
        boletos.push_back(boleto);
    }

    // Setters
    void setIdAutobus(int id) {
        idAutobus = id;
    }

    void setModelo(const string& nuevoModelo) {
        modelo = nuevoModelo;
    }

    void setCapacidadMaxima(int capacidad) {
        capacidadMaxima = capacidad;
    }

    void setRuta(Ruta* nuevaRuta) {
        ruta = nuevaRuta;
    }
};

//Funcion para ver el historial de los boletos comprados
void verHistorialBoletos(const string& nombreArchivo) {
    vector<Boleto*> boletos;

    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de boletos." << endl;
        return;
    }

    int idBoleto, costo, asiento;
    string origen, destino;
    int dia, mes, ano;
    int horas, minutos;
    bool archivoLeido = false;

    while (archivo >> idBoleto >> origen >> destino >> dia >> mes >> ano >> horas >> minutos >> costo >> asiento) {
        archivoLeido = true;
        Fecha fecha(dia, mes, ano);
        Hora hora(horas, minutos);
        Boleto* boleto = new Boleto(idBoleto, origen, destino, fecha, hora, costo);
        boleto->setAsiento(asiento);
        boletos.push_back(boleto);
    }

    archivo.close();

    if (!archivoLeido) {
        cout << "El archivo de boletos está vacío." << endl;
        return;
    }

    cout << "Historial de boletos:" << endl;
    for (const Boleto* boleto : boletos) {
        cout << "ID del boleto: " << boleto->getIdBoleto() << endl;
        cout << "Origen: " << boleto->getOrigen() << endl;
        cout << "Destino: " << boleto->getDestino() << endl;
        cout << "Fecha: " << boleto->getFecha() << endl;
        cout << "Hora: " << boleto->getHora() << endl;
        cout << "Costo: $" << boleto->getCosto() << endl;
        cout << "Asiento: " << boleto->getAsiento() << endl;
        cout << "------------------------" << endl;
    }

    int opcion;
    cout << "1. Agregar nuevo boleto" << endl;
    cout << "2. Volver al menú principal" << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;

    if (opcion == 1) {
        int idBoleto, costo, asiento;
        string origen, destino;
        int dia, mes, ano;
        int horas, minutos;

        cout << "Ingrese el ID del boleto: ";
        cin >> idBoleto;
        cin.ignore();

        cout << "Ingrese el origen: ";
        getline(cin, origen);

        cout << "Ingrese el destino: ";
        getline(cin, destino);

        cout << "Ingrese la fecha (día mes año): ";
        cin >> dia >> mes >> ano;

        cout << "Ingrese la hora (horas minutos): ";
        cin >> horas >> minutos;

        cout << "Ingrese el costo: ";
        cin >> costo;

        cout << "Ingrese el número de asiento: ";
        cin >> asiento;

        Fecha fecha(dia, mes, ano);
        Hora hora(horas, minutos);
        Boleto* boleto = new Boleto(idBoleto, origen, destino, fecha, hora, costo);
        boleto->setAsiento(asiento);
        boletos.push_back(boleto);

        cout << "Boleto agregado exitosamente." << endl;
    }
    else if (opcion == 2) {
        return;
    }
    else {
        cout << "Opción inválida. Volviendo al menú principal." << endl;
        return;
    }

    // Sobreescribir el archivo
    ofstream archivoSalida(nombreArchivo, ios::out | ios::trunc);
    if (!archivoSalida.is_open()) {
        cout << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }

    for (const Boleto* boleto : boletos) {
        archivoSalida << boleto->getIdBoleto() << " ";
        archivoSalida << boleto->getOrigen() << " ";
        archivoSalida << boleto->getDestino() << " ";
        archivoSalida << boleto->getFecha().getDia() << " ";
        archivoSalida << boleto->getFecha().getMes() << " ";
        archivoSalida << boleto->getFecha().getAno() << " ";
        archivoSalida << boleto->getHora().getHoras() << " ";
        archivoSalida << boleto->getHora().getMinutos() << " ";
        archivoSalida << boleto->getCosto() << " ";
        archivoSalida << boleto->getAsiento() << endl;
    }

    archivoSalida.close();

    cout << "El archivo de boletos ha sido actualizado." << endl;

    // Liberar la memoria de los boletos
    for (Boleto* boleto : boletos) {
        delete boleto;
    }
}

// Función para liberar memoria de los objetos creados
template<typename T>
void liberarMemoria(const vector<T*>& objetos) {
    for (const auto& objeto : objetos) {
        delete objeto;
    }
}

// Función para mostrar la información de las rutas
void mostrarInformacionRutas(const Ruta& ruta1, const Ruta& ruta2, const Ruta& ruta3) {
    cout << "Información de las Rutas:" << endl;
    cout << "Ruta 1 - ID: " << ruta1.getIdRuta() << ", Origen: " << ruta1.getOrigen() << ", Destino: " << ruta1.getDestino() << endl;
    cout << "Ruta 2 - ID: " << ruta2.getIdRuta() << ", Origen: " << ruta2.getOrigen() << ", Destino: " << ruta2.getDestino() << endl;
    cout << "Ruta 3 - ID: " << ruta3.getIdRuta() << ", Origen: " << ruta3.getOrigen() << ", Destino: " << ruta3.getDestino() << endl;
}

int main() {
    vector<Usuario*> usuarios;
    vector<Boleto*> boletos;

    // Crear objetos de tipo Ruta
    Ruta ruta1(456, "Ciudad A", "Ciudad B");
    Ruta ruta2(467, "Ciudad C", "Ciudad D");
    Ruta ruta3(478, "Ciudad E", "Ciudad F");

    // Asignar autobuses a las rutas
    Autobus autobus1(1, "Modelo 1", 50, "Conductor 1", 1);
    Autobus autobus2(2, "Modelo 2", 40, "Conductor 2", 2);
    Autobus autobus3(3, "Modelo 3", 30, "Conductor 3", 3);

    ruta1.setAutobus(&autobus1);
    ruta2.setAutobus(&autobus2);
    ruta3.setAutobus(&autobus3);

    int opcion = 0;

    while (opcion != 5) {
        cout << "\n----- Menú Principal -----" << endl;
        cout << "1. Crear nuevo usuario" << endl;
        cout << "2. Ver historial de boletos" << endl;
        cout << "3. Agregar nuevo boleto" << endl;
        cout << "4. Mostrar información de las rutas" << endl;
        cout << "5. Salir \n" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            int idUsuario;
            string nombreUsuario, correo, contrasena;

            cout << "Ingrese el ID del usuario: ";
            cin >> idUsuario;

            cout << "Ingrese el nombre del usuario: ";
            cin >> nombreUsuario;

            cout << "Ingrese el correo electrónico del usuario: ";
            cin >> correo;

            cout << "Ingrese la contraseña del usuario: ";
            cin >> contrasena;

            Usuario* nuevoUsuario = new Usuario(idUsuario, nombreUsuario, idUsuario, correo, contrasena);

            cout << "Usuario creado exitosamente." << endl;
            
        }
        else if (opcion == 2) {
            verHistorialBoletos("boletos.txt");
        }
        else if (opcion == 3) {
            int idBoleto, costo, asiento;
            string origen, destino;
            int dia, mes, ano;
            int horas, minutos;

            cout << "Ingrese el ID del boleto: ";
            cin >> idBoleto;
            cin.ignore();

            cout << "Ingrese el origen: ";
            getline(cin, origen);

            cout << "Ingrese el destino: ";
            getline(cin, destino);

            cout << "Ingrese la fecha (día mes año): ";
            cin >> dia >> mes >> ano;

            cout << "Ingrese la hora (horas minutos): ";
            cin >> horas >> minutos;

            cout << "Ingrese el costo: ";
            cin >> costo;

            cout << "Ingrese el número de asiento: ";
            cin >> asiento;

            Fecha fecha(dia, mes, ano);
            Hora hora(horas, minutos);
            Boleto* boleto = new Boleto(idBoleto, origen, destino, fecha, hora, costo);
            boleto->setAsiento(asiento);
            boletos.push_back(boleto);

            cout << "\nBoleto agregado exitosamente.\n" << endl;
        }
        else if (opcion == 4) {
            mostrarInformacionRutas(ruta1, ruta2, ruta3);
        }
        else if (opcion == 5) {
            cout << "\nSaliendo del programa..." << endl;
            break; // Termina la ejecución del programa
        }
        else {
            cout << "\nOpción inválida. Por favor, ingrese una opción válida.\n" << endl;
        }
    }

    // Liberar memoria
    liberarMemoria(usuarios);
    liberarMemoria(boletos);

    return 0;
}
