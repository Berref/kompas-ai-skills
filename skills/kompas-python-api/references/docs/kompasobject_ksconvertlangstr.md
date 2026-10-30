# ksConvertLangStr - Конвертировать строку src в dst в соответствии с текущим словарем

[API интерфейсов. Версия 5](ag57940.html) > [KompasObject - Интерфейс API КОМПАС ](kompasobject.html) > [KompasObject - методы ](kompasobject_methods.html) |  Scroll [ [ [ ](kompasobject_ksconvertlangstrex.html "К следующему разделу")](kompasobject_methods.html "На уровень выше")](kompasobject_ksconvertlangmenu.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](kompasobject.html)

Аналог данного метода при использовании экспортных функций [ksConvertLangStr](ksconvertlangstr.html).

Синтаксис Automation:

BSTR ksConvertLangStr (BSTR src);

Входной параметр:

src | \- исходная строка.  
---|---  
  
Возвращаемое значение:

| \- переведенная строка.  
---|---  
  
Примечание.

Словарь сохраняется в файле с расширением dic. Строки файла должны иметь следующий формат:

"Вращение"="Rotation"

"Параметры"="Parameters"

...

...

"Перемещение"="Moving"

Строки файла должны быть отсортированы по алфавиту.

Подразделы:

(отсутствуют)
