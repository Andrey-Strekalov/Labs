#include <iostream>
#include <string>
#include <cctype>    // Äëÿ èñïîëüçîâàíèÿ isupper
#include <algorithm> // Äëÿ ôóíêöèè sort
#include <Windows.h> // Äëÿ èçìåíåíèÿ êîäèðîâêè êîíñîëè (Windows)

// Ôóíêöèÿ ðàçäåëÿåò ñòðîêó íà çàãëàâíûå è ñòðî÷íûå ñèìâîëû
void filtSymbols(std::string* text, std::string* A_line, std::string* a_line) {
	for (char s : *text) {           // Ïðîõîäèì ïî êàæäîìó ñèìâîëó ñòðîêè
		if (isupper(s)) {            // Åñëè ñèìâîë çàãëàâíûé
			*A_line += s;            // Äîáàâëÿåì â ñòðîêó çàãëàâíûõ áóêâ
		}
		else {                     // Åñëè ñèìâîë ñòðî÷íûé
			*a_line += s;            // Äîáàâëÿåì â ñòðîêó ñòðî÷íûõ áóêâ
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	std::string text = "";           // Èñõîäíàÿ ñòðîêà
	std::string* txt_ptr = &text;    // Óêàçàòåëü íà èñõîäíóþ ñòðîêó

	std::cout << "Ââåäèòå òåêñò: ";
	std::getline(std::cin, text);    // Ñ÷èòûâàåì ñòðîêó îò ïîëüçîâàòåëÿ

	std::string string_cptl = "", string_lwc = ""; // Ñòðîêè äëÿ çàãëàâíûõ è ñòðî÷íûõ ñèìâîëîâ
	std::string* cptl_ptr = &string_cptl;          // Óêàçàòåëü íà ñòðîêó çàãëàâíûõ
	std::string* lwc_ptr = &string_lwc;            // Óêàçàòåëü íà ñòðîêó ñòðî÷íûõ

	filtSymbols(txt_ptr, cptl_ptr, lwc_ptr);      // Âûçûâàåì ôóíêöèþ äëÿ ðàçäåëåíèÿ ñèìâîëîâ

	sort(string_cptl.begin(), string_cptl.end()); // Ñîðòèðóåì çàãëàâíûå ñèìâîëû ïî àëôàâèòó
	std::cout << string_cptl << std::endl;        // Âûâîäèì îòñîðòèðîâàííûå çàãëàâíûå ñèìâîëû

	return 0;
}
