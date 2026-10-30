# ksChoiceAttr - Вывести диалог для просмотра атрибутов объекта и выбора нужного атрибута

[API интерфейсов. Версия 5](ag57940.html) > [Интерфейсы работы с атрибутами ](ck1761772.html) > [Интерфейс работы с атрибутами (ksAttributeObject) ](ksattributeobject.html) > [ksAttributeObject - методы ](ksattributeobject_methods.html) |  Scroll [ [ [ ](ksattributeobject_kschoiceattr3d.html "К следующему разделу")](ksattributeobject_methods.html "На уровень выше")](ksattributeobject_ksaddattrrow.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksattributeobject.html)

Аналог данного метода при использовании API экспортных функций - [ChoiceAttr](choiceattr.html).

Синтаксис Automation:

long ksChoiceAttr (reference pObj);

Входной параметр:

pObj | \- указатель на объект, к которому подключены атрибуты.  
---|---  
  
Возвращаемое значение:

указатель на атрибут | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

Указатель на объект reference pObj может быть получен следующими способами:

•с помощью свойства reference интерфейса соответствующего объекта,

•с помощью интерфейса итератора [ksIterator](ksiterator.html) и методов [ksIterator::ksCreateIterator](ksiterator_kscreateiterator.html), [ksIterator::ksMoveIterator](ksiterator_ksmoveiterator.html).

Подразделы:

(отсутствуют)
