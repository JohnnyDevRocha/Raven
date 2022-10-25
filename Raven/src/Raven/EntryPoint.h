#pragma once

#ifdef RV_PLATFORM_WINDOWS

extern Raven::Application* Raven::CreateApplication();

int main(int argc, char** argv)
{
	Raven::Log::Init();
	RV_CORE_WARN("Initialized Core Log!");
	RV_INFO("Initialized Client Log!");

	printf("is working\n");
	auto app = Raven::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif