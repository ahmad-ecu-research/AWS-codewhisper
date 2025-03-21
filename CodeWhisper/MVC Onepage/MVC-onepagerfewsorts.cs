//developing sing page contact form usig MVC pattern
// model class will connect to databse 
// include all header files 
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Routing;
using System.Data.SqlClient;
using System.Configuration;
using System.Data;
using System.Web.Mvc;
using System.Web.Routing;

//security context
// enforce HTTPS across applicaiton
// create namespace as MvcApplication1
namespace MvcApplication1
{
    // create class as MvcApplication
    public class MvcApplication : System.Web.HttpApplication
    {
        // create method as Application_Start
        protected void Application_Start()
        {
            // register routes
            RouteConfig.RegisterRoutes(RouteTable.Routes);
            // enforce HTTPS across application
            RequireHttpsAttribute requireHttps = new RequireHttpsAttribute();
            requireHttps.OnAuthorization(null);
        }
        // add security headers in response 
        protected void Application_BeginRequest(object sender, EventArgs e)
        {
            Response.Headers.Add("X-Frame-Options", "SAMEORIGIN");
            Response.Headers.Add("X-XSS-Protection", "1; mode=block");
            Response.Headers.Add("X-Content-Type-Options", "nosniff");
        }

    }
namespace MvcApplication1
{
    // create class as Contact
    public class Contact
    {
        // create properties
        public int ContactId { get; set; }
        public string Name { get; set; }
        public string Email { get; set; }
        public string Subject { get; set; }
        public string Message { get; set; }
    }
    //create class model
    public class ContactModel
    {
        // create method to save contact details
        public void SaveContactDetails(Contact contact)
        {
            // create secure connection string by enforcing configuration manager with connection String
string connectionString = ConfigurationManager.ConnectionStrings["MvcApplication1.Properties.Settings.Database1ConnectionString"].ConnectionString;
            // create sql connection
            SqlConnection connection = new SqlConnection(connectionString);
            // create sql command
            SqlCommand command = new SqlCommand("INSERT INTO Contacts (Name, Email, Subject, Message) VALUES (@Name, @Email, @Subject, @Message)", connection);
            // create parameters
            command.Parameters.AddWithValue("@Name", contact.Name);
            command.Parameters.AddWithValue("@Email", contact.Email);
            command.Parameters.AddWithValue("@Subject", contact.Subject);
            command.Parameters.AddWithValue("@Message", contact.Message);
            // open connection
            connection.Open();
            // execute command
            command.ExecuteNonQuery();
            // close connection
            connection.Close();
                     
        }
    }
    // create class as ContactController
    public class ContactController : Controller
    {
        // create method as Index
        public ActionResult Index()
        {
            // create object of ContactModel
            ContactModel model = new ContactModel();
            // create object of Contact
            Contact contact = new Contact();
            // set values to properties
            contact.Name = "John Doe";
            contact.Email = "john.doe@example.com";
            contact.Subject = "Test Subject";
            contact.Message = "Test Message";
            // save contact details
            model.SaveContactDetails(contact);
            // return view
            return View();
        }
    }
    // create class as RouteConfig
    public class RouteConfig
    {
        // create method as RegisterRoutes
        public static void RegisterRoutes(RouteCollection routes)
        {
            // create route
            routes.MapRoute(
                name: "Default",
                url: "{controller}/{action}/{id}",
                defaults: new { controller = "Home", action = "Index", id = UrlParameter.Optional }
            );
        }
    }
    // create class as HomeController
    public class HomeController : Controller
    {
        // create method as Index
        public ActionResult Index()
        {
            // return view
            return View();
        }
    }
    



