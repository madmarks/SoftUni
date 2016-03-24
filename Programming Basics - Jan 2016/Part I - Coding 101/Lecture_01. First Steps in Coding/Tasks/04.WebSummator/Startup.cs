using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(WebSummator.Startup))]
namespace WebSummator
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
