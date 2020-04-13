package gen;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.StandardCopyOption;
import java.util.List;

import javax.xml.XMLConstants;
import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBElement;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;
import javax.xml.datatype.DatatypeConfigurationException;
import javax.xml.datatype.DatatypeFactory;
import javax.xml.transform.Source;
import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;

import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

import gen.Company;
import gen.Project;
import gen.Name;
import gen.ObjectFactory;
import gen.Boss;
import gen.Employee;

public class Main {

	private static final String XML_DOCUMENT_FILE = "src/xml.xml";
	private static final String XML_BACKUP_DOCUMENT_FILE = "src/xmlbckp.xml";
	private static final String XML_SCHEMA_FILE = "src/xmlschema.xsd";

	public static void main(String[] args) throws DatatypeConfigurationException {
		try {
			resetXML();

			SchemaFactory schemaFactory = SchemaFactory.newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
			Schema schema = schemaFactory.newSchema(new File(XML_SCHEMA_FILE));

			JAXBContext jaxbContext = JAXBContext.newInstance(ObjectFactory.class);

			Unmarshaller unmarshaller = jaxbContext.createUnmarshaller();
			unmarshaller.setSchema(schema);

			Marshaller marshaller = jaxbContext.createMarshaller();
			marshaller.setSchema(schema);
			marshaller.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
			marshaller.setProperty(Marshaller.JAXB_ENCODING, "UTF-8");
			marshaller.setProperty(Marshaller.JAXB_NO_NAMESPACE_SCHEMA_LOCATION, XML_SCHEMA_FILE);

			Company root = loadXML(unmarshaller);
			//modify
			if (root.getEmployees().getEmployee().size() > 0) {
				root.getEmployees().getEmployee().get(0).getName().setFirstname("Zsolt");
			}
			
			if (root.getBosses().getBoss().size() > 0) {
				root.getBosses().getBoss().get(0).getName().setLastname("Mezõkeresztesi");
			}
			
			//delete
			
			if (root.getProjects().getProject().size() > 0) {
				root.getProjects().getProject().remove(root.getProjects().getProject().get(2));
			}
			
			//add
			if (root.getBosses().getBoss().size() > 0) {
				Boss newBoss = new Boss();

				newBoss.setTaxID("8477484");;
				Name name = new Name();
				name.setLastname("Újvári");
				name.setFirstname("Zoltán");
				newBoss.setName(name);
				newBoss.setBirthdate(DatatypeFactory.newInstance().newXMLGregorianCalendar("1991-03-15"));
			}
			
			if (root.getProjects().getProject().size() > 0) {
				Project newProject = new Project();
				
				newProject.setCosts(158000);
				newProject.setID("84848484");
				newProject.setTheme("Calculator");
			}

			//list
			String lastName = "Újvári";
			String firstName = "Zoltán";
			int j=0;

			List<Employee> employees = root.getEmployees().getEmployee();
			for (int i = 0; i < employees.size(); i++) {
				if (employees.get(i).getName().getLastname().toString().equals(lastName)
						&& employees.get(i).getName().getFirstname().toString().equals(firstName)) {
					j=1;
				}
			}

			if (j!=1) 
				{
				System.out.println("Can not find the person!");
				} 
			else 
			{
				System.out.println("The person you are looking for is "+ lastName + " " + firstName +"");
			}
			saveXML(marshaller, root);

		} catch (SAXException | JAXBException | DatatypeConfigurationException e) {
			e.printStackTrace();
		}
	}

	private static void resetXML() {
		try {
			Files.copy(new File(XML_BACKUP_DOCUMENT_FILE).toPath(), new File(XML_DOCUMENT_FILE).toPath(),
					StandardCopyOption.REPLACE_EXISTING);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static Company loadXML(Unmarshaller unmarshaller) throws JAXBException {
		File xmlFile = new File(XML_DOCUMENT_FILE);
		Source xmlSource = new StreamSource(xmlFile);
		JAXBElement<Company> jaxbElement = unmarshaller.unmarshal(xmlSource, Company.class);

		return jaxbElement.getValue();
	}

	private static void validateXML(Marshaller marshaller, Company root) throws JAXBException {
		marshaller.marshal(root, new DefaultHandler());
	}

	private static void saveXML(Marshaller marshaller, Company root) throws JAXBException {
		File xmlFile = new File(XML_DOCUMENT_FILE);

		validateXML(marshaller, root);
		marshaller.marshal(root, xmlFile);
	}

}
