////////////////////////////////////////////////////////////////////////////////
//
// Converter - Класс конвертера - мой конвертер
//
////////////////////////////////////////////////////////////////////////////////
#ifndef __CONVERTER_H
#define __CONVERTER_H

class KompasConverter;
class LibConverterParam;


///////////////////////////////////////////////////////////////////////////////
//
// Класс конвертера - мой конвертер
//
///////////////////////////////////////////////////////////////////////////////
class LibConverter 
{

protected :
  // true - сохранить стиль линий
  // false - не сохранить стиль линий
  bool lineStyle;
  
  // Указатель на компас конвертер
  KompasConverter  * m_pConverter;
  // Указатель на класс параметров конвертера
  LibConverterParam * m_pConverterParam; 

public:  
                     LibConverter ();
                     ~LibConverter();
  
  // Получить указатель на компас конвертер
  KompasConverter *  GetKompasConverter ();
  void               InterfaceNull      () { m_pConverter      = NULL; }
  void               InterfaceParamNull () { m_pConverterParam = NULL; }

  // Запустить визуальное редактирование параметров  
  BOOL               VisualEditConvertParam( OLE_HANDLE parentHwnd, long command );    
  // Конвертировать
  long               Convert            ( LPCTSTR inputFile, LPCTSTR outFile, long command, BOOL showParam );
  // Проверить можно ли выгрузить библиотеку из памяти
  BOOL               GetCanUnLoadLibrary();
  // Выполнить команду меню
  void               ExecuteCommand     ( unsigned int com );
  // Получить указатель на класс параметров конвертера
  LibConverterParam * GetConvertParam   ( long command );
  // Получить фильтр и команду для конвертера по типу документа
  BSTR               GetFilter          ( long docType, BOOL saveAs, long * command );
  // Получить фильтр и команду для конвертера по расширению документа
  BSTR               GetFilter          ( LPCTSTR ext, BOOL saveAs, long * command );
  
  // Реализация интерфейса параметров конвертера
  void               SetSaveLineStyle   ( bool val);
  bool               GetSaveLineStyle   ();
};

LibConverter & GetLibConverter();      // Получить указатель на конвертер
void          ConverterDestroy();      // Удаление конвертера

#endif // __CONVERTER_H
