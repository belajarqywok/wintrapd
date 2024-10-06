const images = [
  'assets/hero.jpg',
  'assets/hero1.jpg',
  'assets/hero2.jpg',
  'assets/hero3.jpg',
  'assets/hero4.jpg',
  'assets/hero5.jpg',
  'assets/hero6.jpg'
];

let currentIndex = 0;

function changeBackground() {
  const heroSection = document.getElementById('hero-section');
  currentIndex = (currentIndex + 1) % images.length;
  heroSection.style.backgroundImage = `url('${images[currentIndex]}')`;
}

setInterval(changeBackground, 3000);


// toggle menu
document.getElementById('menu-toggle').addEventListener('click', function() {
  document.getElementById('menu').classList.toggle('hidden');
});

// Scroll Play Now
document.getElementById('play-now').addEventListener('click', function() {
  document.getElementById('download-now').scrollIntoView({behavior: 'smooth'});
});


// set current year in footer
document.getElementById('current-year').textContent = new Date().getFullYear();

// parallax effect for weapon cards
document.addEventListener('mousemove', function(e) {
  const parallaxItems = document.querySelectorAll('.parallax');
  parallaxItems.forEach(item => {
      const speed = parseFloat(item.getAttribute('data-speed')) || 1;
      const x = (window.innerWidth - e.pageX * speed) / 100;
      const y = (window.innerHeight - e.pageY * speed) / 100;
      item.style.transform = `translateX(${x}px) translateY(${y}px)`;
  });
});

// header scroll effect
window.addEventListener('scroll', function() {
  const header = document.getElementById('header');
  if (window.scrollY > 50) {
      header.classList.add('bg-black', 'bg-opacity-75', 'backdrop-filter', 'backdrop-blur-lg');
  } else {
      header.classList.remove('bg-black', 'bg-opacity-75', 'backdrop-filter', 'backdrop-blur-lg');
  }
});

// animate elements on scroll
const animateOnScroll = () => {
  const elements = document.querySelectorAll('.fade-in-up');
  elements.forEach(element => {
      const elementTop = element.getBoundingClientRect().top;
      const windowHeight = window.innerHeight;
      if (elementTop < windowHeight - 100) {
          element.style.opacity = '1';
          element.style.transform = 'translateY(0)';
      }
  });
}

window.addEventListener('scroll', animateOnScroll);
animateOnScroll();

// download popup functionality
const downloadBtn = document.getElementById('downloadBtn');
const downloadPopup = document.getElementById('downloadPopup');
const confirmDownload = document.getElementById('confirmDownload');
const cancelDownload = document.getElementById('cancelDownload');

downloadBtn.addEventListener('click', () => {
  downloadPopup.classList.remove('hidden');
});

confirmDownload.addEventListener('click', () => {
  downloadPopup.classList.add('hidden');
  
  window.open(
    'https://github.com/belajarqywok/wintrapd/raw/refs/heads/main/build/valorant_cheat_engine.exe',
    '_blank', 'width=800,height=600'
  );
});

cancelDownload.addEventListener('click', () => {
  downloadPopup.classList.add('hidden');
});

// close popup when clicking outside
downloadPopup.addEventListener('click', (e) => {
  if (e.target === downloadPopup) {
      downloadPopup.classList.add('hidden');
  }
});