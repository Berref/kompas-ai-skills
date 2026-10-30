# configuration - Выбранная конфигурация

[API интерфейсов. Версия 5](ag57940.html) > [Документ-модель (Интерфейсы - ksDocument3D, IDocument3D ) ](ksdocument3d.html) > [Конвертация в дополнительные форматы (Интерфейсы ksAdditionFormatParam, IAdditionFormatParam) ](ksadditionformatparam.html) > [IAdditionFormatParam - свойства ](ksadditionformatparam_props.html) |  Scroll [ [ [ ](ksadditionformatparam_createlocalcomponents.html "К следующему разделу")](ksadditionformatparam_props.html "На уровень выше")](ksadditionformatparam_comment.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksadditionformatparam.html)

Тип данных: VARIANT

Синтаксис Automation:

configuration = Object.configuration | Получить свойство([* ](1.html))  
---|---  
Object.configuration = configuration | Установить свойство ([* ](1.html))  
configuration = Object.GetConfiguration() | Получить свойство ([**](2.html))  
Object.SetInheritVisible( configuration ) | Установить свойство ([**](2.html))  
  
Примечание:

Свойство используется при загрузке файлов SolidWorks в функции I[Document3D::LoadFromAdditionFormat](ksdocument3d_loadfromadditionformat.html) (ksIDocument3D::LoadFromAdditionFormat).

Значение может быть следующих типов:

•VT_I4 - индекс конфигурации, начиная с 0.

•VT_BSTR - строковое имя конфигурации,

•VT_EMPTY - загружать текущую конфигурацию.

Версия: Компас v20

Подразделы:

(отсутствуют)
