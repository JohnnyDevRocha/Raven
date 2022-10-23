#pragma once

#ifdef RV_PLATFORM_WINDOWS

extern Raven::Application* Raven::CreateApplication();

int main(int argc, char** argv)
{
	printf("is working\n");
	auto app = Raven::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif