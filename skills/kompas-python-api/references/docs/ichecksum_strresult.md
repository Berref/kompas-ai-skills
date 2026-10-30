# StrResult- Получить контрольную сумму в виде строки

[API интерфейсов. Версия 7](applicate.html) > [Менеджер библиотек ](library_maneger.html) > [Интерфейс ICheckSum ](ichecksum.html) > [ICheckSum - свойства ](ichecksum_props.html) |  Scroll [ [ [ ](ichecksum_version.html "К следующему разделу")](ichecksum_props.html "На уровень выше")](ichecksum_result.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ichecksum.html)

Тип данных: BSTR (строка)

Синтаксис Automation:

StrResult = iObject.StrResult | Получить свойство ([* ](1.html))  
---|---  
StrResult = iObject.GetStrResult() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_StrResult( &StrResult ) | Получить свойство  
---|---  
  
Примечание:

1\. Свойство доступно только для чтения.

2\. Строка контрольной суммы представляет собой последовательность из 32 буквенных латинских символов. Строка инициализированной (очищенной) контрольной суммы представляет собой последовательность aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa.

Подразделы:

(отсутствуют)
