// Ganti IP atau URL dengan milik ESP32 kamu
const espIp = "http://192.168.1.100"; // ← Ganti ini

document.getElementById("onBtn").addEventListener("click", () => {
  fetch(`${espIp}/led/on`)
    .then(res => console.log("LED ON"))
    .catch(err => console.error("Gagal ON:", err));
});

document.getElementById("offBtn").addEventListener("click", () => {
  fetch(`${espIp}/led/off`)
    .then(res => console.log("LED OFF"))
    .catch(err => console.error("Gagal OFF:", err));
});
