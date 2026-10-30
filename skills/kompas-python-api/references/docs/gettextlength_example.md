# GetTextLength - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
/*GetTextLenght_example*/

{

reference pText;

double len1, len2;

len1 = GetTextLenght(« Пример... текста», 1); // Пример... функции GetTextLenght

pText = Text (30, 90, 0, 5, 1, 0,Простой текст);

len2 = GetTextLenghtFromReference(pText); // Пример... функции GetTextLenghtFromReference

}
