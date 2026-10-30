# ksChangeObjectInLibRequest - Изменить фантом или компоненты команд

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) |  Scroll [ [ [ ](ksdocument2d_kschangeobjectsorder.html "К следующему разделу")](ksdocument2d_methods.html "На уровень выше")](ksdocument2d_kschangeleader.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [ksChangeObjectInLibRequest](kschangeobjectinlibrequest.html).

Синтаксис Automation:

long ksChangeObjectInLibRequest (LPDISPATCH info,

LPDISPATCH phantom);

Входные параметры:

info | \- указатель на интерфейс [ksRequestInfo](ksrequestinfo.html),  
---|---  
phantom | \- указатель на интерфейс [ksPhantom](ksphantom.html).  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Во время работы методов [ksDocument2D::ksCursor](ksdocument2d_kscursor.html) и [ksDocument2D::ksPlacement](ksdocument2d_ksplacement.html) может возникнуть необходимость изменить фантом или компоненты команд. Функция ksChangeObjectInLibRequest позволяет передать изменения в цикл ksCursor и ksPlacement. Это может понадобиться для отработки команд пользовательских инструментальных панелей.

Предварительно нужно убедиться, что вызов ksCursor и требование к ksCursor передаются в одном документе. Если какой-либо указатель равен 0, соответствующий параметр не используется.

Подразделы:

(отсутствуют)
