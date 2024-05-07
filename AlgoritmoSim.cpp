#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Función para invertir los bits de un byte.
// Proporciona CONFUSIÓN al invertir los bits de un byte.
char invertBits(char byte) {
    char result = 0;
    for (int i = 0; i < 8; i++) {
        result |= ((byte >> i) & 1) << (7 - i);
    }
    return result;
}

// Operación XOR entre el texto y la clave.
// Proporciona CONFUSIÓN al realizar una operación XOR entre el texto y la clave.
string xorOperation(const string &text, const string &key) {
    string result = "";
    for (size_t i = 0; i < text.size(); i++) {
        result += text[i] ^ key[i % key.size()];
    }
    return result;
}

// Desplazamiento de bits a la izquierda.
// Proporciona DIFUSIÓN al desplazar los bits de cada byte a la izquierda.
string shiftLeft(const string &input) {
    string result = "";
    for (char c : input) {
        result += c << 1;
    }
    return result;
}

// Desplazamiento de bits a la derecha.
// Proporciona DIFUSIÓN al desplazar los bits de cada byte a la derecha.
string shiftRight(const string &input) {
    string result = "";
    for (char c : input) {
        result += c >> 1;
    }
    return result;
}

// Transposición simple de los dos primeros caracteres.
// Proporciona DIFUSIÓN al intercambiar los dos primeros caracteres.
string transpose(const string &input) {
    if (input.size() <= 1) return input;
    return string(1, input[1]) + string(1, input[0]) + (input.size() > 2 ? input.substr(2) : "");
}

// Función inversa de la transposición.
string reverseTranspose(const string &input) {
    return transpose(input);
}

// Convertir una cadena a su representación hexadecimal.
string toHex(const string &input) {
    stringstream ss;
    for (char c : input) {
        ss << hex << setw(2) << setfill('0') << (int)(unsigned char)c;
    }
    return ss.str();
}

// Convertir una cadena hexadecimal a su representación original.
string fromHex(const string &input) {
    string result;
    for (size_t i = 0; i < input.size(); i += 2) {
        string byte = input.substr(i, 2);
        char chr = (char)(int)strtol(byte.c_str(), nullptr, 16);
        result += chr;
    }
    return result;
}

// Función de cifrado.
// Realiza dos rondas de cifrado para robustecer el algoritmo.
string encrypt(const string &plaintext, const string &key) {
    string data = plaintext;
    // Primera ronda de cifrado
    data = xorOperation(data, key);
    data = transpose(data);
    data = shiftLeft(data);  // Desplazamiento de bits a la izquierda
    // Segunda ronda de cifrado
    string temp = "";
    for (char c : data) {  // Aplicar invertBits a cada carácter
        temp += invertBits(c);
    }
    data = temp;  // Reemplazar data con la versión invertida
    data = xorOperation(data, key);
    return toHex(data);
}

// Función de descifrado.
// Realiza dos rondas de descifrado en orden inverso al cifrado.
string decrypt(const string &ciphertext, const string &key) {
    string data = fromHex(ciphertext);
    // Segunda ronda de descifrado (inversa)
    data = xorOperation(data, key);
    string temp = "";
    for (char c : data) {  // Aplicar invertBits a cada carácter
        temp += invertBits(c);
    }
    data = temp;
    // Primera ronda de descifrado (inversa)
    data = shiftRight(data);  // Desplazamiento de bits a la derecha
    data = reverseTranspose(data);
    data = xorOperation(data, key);
    return data;
}


int main() {
    string plaintext, key;
    cout << "Ingrese el texto a cifrar (hasta 100 caracteres): ";
    getline(cin, plaintext);
    cout << "Ingrese la clave simétrica (hasta 16 caracteres): ";
    getline(cin, key);

    string encryptedText = encrypt(plaintext, key);
    cout << "Texto cifrado: " << encryptedText << endl;

    string decryptedText = decrypt(encryptedText, key);
    cout << "Texto descifrado: " << decryptedText << endl;

    return 0;
}
