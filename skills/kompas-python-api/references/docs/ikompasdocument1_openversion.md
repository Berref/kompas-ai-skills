# OpenVersion - Версия файла, с которой документ был сохранен

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument1 ](ikompasdocument1.html) > [IKompasDocument1 - свойства ](ikompasdocument1_props.html) |  Scroll [ [ [ ](ikompasdocument1_organization.html "К следующему разделу")](ikompasdocument1_props.html "На уровень выше")](ikompasdocument1_objectsbyattr.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument1.html)

Тип данных: long

Синтаксис Automation:

OpenVersion = Object.OpenVersion | Получить свойство ([* ](1.html))  
---|---  
OpenVersion = Object.GetOpenVersion() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

Object.get_OpenVersion( &OpenVersion ) | Получить свойство  
---|---  
  
Примечание:

Свойство доступно только для чтения

Свойство возвращает номер версии Компас, с которой документ был сохранен последний раз в случае открытия документа с диска.

Если документ сохранен в официальных версиях дистрибутива Компас, свойство вернет значение из перечисления [ksSaveDocumentVersionEnum](kssavedocumentversionenum.html).

Если документ сохранен в промежуточных версиях, может вернуться числовая версия потока.

Подразделы:

(отсутствуют)
