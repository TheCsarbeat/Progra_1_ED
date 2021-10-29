
from fpdf import FPDF

def crearPDFValidacion(lista,cedula):
    """
    Funcionamiento: Se encarga de las validaciones E/S del pdf
    Entradas: lista: base de datos, Cedula, a buscar
    Salidas: Archivo pdf
    """
    cedula=cedula.get()
    if not validarExistente(cedula,lista):
        messagebox.showwarning(title=tittle, message="No se ha encontrado la licencia ligada a esta cédula")
    else:
        crearPDf(lista[obtenerPosicion(cedula,lista)].mostrarDatos())
        

def crearPDf(datos):
    """
    Funcionamiento: Se encarga de crear el pdf de la licenca
    Entradas: Datos: una tupla con los datos
    Salidas: Archivo pdf
    """
    pdf = FPDF('P', 'mm',(150,90))
    pdf.add_page()
    

    # El titulo de COSTA RICA
    pdf.set_text_color(0, 195, 246)
    pdf.cell(0, 5, 'REPUBLICA DE COSTA RICA', 0,1)

    # Titulo de Licencia
    pdf.set_font('arial', '', 14)
    pdf.set_text_color(255, 0, 0)
    pdf.cell(0, 5, 'Licencia de Conducir', 0,1)

    # Cédula de identificación
    pdf.set_font('arial', 'B', 14)
    pdf.set_text_color(0, 0, 0)
    pdf.cell(8, 5, 'N°: ')
    # EL número de la base de datos
    pdf.set_font('arial', 'B', 14)
    pdf.set_text_color(255, 0, 0)
    pdf.cell(8, 5, 'CI-'+datos[0],0,1)

    # Fecha de Expedición
    pdf.set_font('arial', 'B', 14)
    pdf.set_text_color(0, 0, 0)
    pdf.cell(30, 5, 'Expedición: ')
    # la Fecha de la base de datos
    pdf.set_font('arial', '', 14)
    pdf.set_text_color(0, 0, 0)
    pdf.cell(8, 5, datos[3],0,1)

    # Fecha de Nacimiento
    pdf.set_font('arial', 'B', 14)
    pdf.set_text_color(0, 0, 0)
    pdf.cell(30, 5, 'Nacimiento: ')
    # la Fecha de la base de datos
    pdf.set_font('arial', '', 14)
    pdf.set_text_color(0, 0, 0)
    pdf.cell(8, 5, datos[2],0,1)

    # Fecha de Vecimiento
    pdf.set_font('arial', 'B', 14)
    pdf.set_text_color(0, 0, 0)
    pdf.cell(31, 5, 'Vencimiento: ')
    # la Fecha de la base de datos
    pdf.set_font('arial', '', 14)
    pdf.set_text_color(255, 0, 0)
    pdf.cell(8, 5, datos[4],0,1)

    # Tipo de licencia
    pdf.set_font('arial', '', 14)
    pdf.set_text_color(255, 0, 0)
    pdf.cell(12, 6, 'Tipo: ')
    # la Fecha de la base de datos
    pdf.set_font('arial', '', 18)
    pdf.set_text_color(255, 0, 0)
    pdf.cell(8, 6, datos[5],0,1)

    # Si es Donador
    if datos[7]:
        pdf.set_font('arial', '', 14)
        pdf.set_text_color(255, 0, 0)
        pdf.cell(5, 5, 'Donador',0,1)

    # Tipo de Sangre
    pdf.set_font('arial', '', 14)
    pdf.set_text_color(0, 0, 0)
    pdf.cell(10, 5, 'T.S: ')
    # la Fecha de la base de datos
    pdf.set_font('arial', '', 14)
    pdf.set_text_color(255, 0, 0)
    pdf.cell(8, 5, datos[6],0,1)

    # nombre de la persona
    pdf.set_font('arial', 'B', 18)
    pdf.set_text_color(0, 0, 0)
    pdf.cell(8, 6, datos[1],0,1)

    # Hora Actual
    pdf.set_font('arial', '', 10)
    pdf.set_text_color(0, 0, 0)
    pdf.cell(10, 5, generarFechaExp()+" "+obtenerHoraActual()+ " "+traducirSedeReporte(datos[8]))
    crearArchivo(pdf, datos[0])
        
def crearArchivo(pdf, cedula):
    """
    Funcionamiento: Se encarga de validar que el archivo no esté abierto
    Entradas: pdf: objeto de pdf
    Salidas: Archivo pdf
    """
    try:
        pdf.output('prueba.pdf')
        print ('exito')
    except:
        print('no exito')

datos=['awefqaw','aefdqwef','marco','robo','fabi','adhfiuaq','aidufhqaeihf','aksdhf','leslie']
crearPDF(datos)
